// 도시 왕복하기2 - 플래티넘3
// 어떤 길을 한 번만 지날 수 있다 :== 그 간선의 용량이 1
// 정점을 한 번만 지날 수 있다는 조건 -> 정점 하나를 2개의 정점으로 나눠서, 그 사이의 간선 용량을 1로 지정한다.
#include<bits/stdc++.h>
using namespace std;

const int MAX_V = 801;
int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int N, P; cin >> N >> P;
    for(int i = 0; i < P; ++i){
        int u_in, v_in; cin >> u_in >> v_in;
        int u_out = u_in + 400, v_out = v_in + 400;
    
        c[u_in][u_out] = 1;
        c[v_in][v_out] = 1;
        c[u_out][v_in] = 1;
        c[v_out][u_in] = 1;

        adj[u_in].push_back(u_out);
        adj[v_in].push_back(v_out);
        adj[u_out].push_back(v_in);
        adj[v_out].push_back(u_in);
        // 역방향 간선 추가
        adj[u_in].push_back(v_out);
        adj[v_in].push_back(u_out); 
    }

    int total = 0, s = 1 + 400, t = 2;

    while(true){
        int prev[MAX_V];
        fill(prev, prev+MAX_V, -1);
        queue<int> Q;
        Q.push(s);
        while(!Q.empty() && prev[t] == -1){
            int cur = Q.front(); Q.pop();
            for(int next : adj[cur]){
                if(c[cur][next] - f[cur][next] > 0 && prev[next] == -1){
                    prev[next] = cur;
                    Q.push(next);
                    if(next == t) break;
                }
            }
        }
        if(prev[t] == -1) break;

        for(int i = t; i != s; i = prev[i]){
            f[prev[i]][i]++;
            f[i][prev[i]]--;
        }
        total++;
    }
    cout << total;
}