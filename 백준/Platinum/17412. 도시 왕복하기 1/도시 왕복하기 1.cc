// 도시 왕복하기1 - 플래티넘4
// 어떤 길을 한 번만 지날 수 있다 :== 그 간선의 용량이 1
#include<bits/stdc++.h>
using namespace std;

const int MAX_V = 401;
int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int N, P; cin >> N >> P;
    for(int i = 0; i < P; ++i){
        int u, v; cin >> u >> v;
    
        c[u][v] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int total = 0, s = 1, t = 2;

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