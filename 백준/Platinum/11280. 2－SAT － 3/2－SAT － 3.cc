// 2-SAT - 3 - 플래티넘4
#include <bits/stdc++.h>
#define MAX 20001
using namespace std;

int N, M, cnt;
int scc_num, order_scc[MAX], disc[MAX];
vector<int> adj[MAX];
vector<vector<int>> SCC;
stack<int> S;

int scc_DFS(int curr){
    disc[curr] = ++cnt;
    S.push(curr);

    int value = disc[curr];
    for(int next : adj[curr]){
        if(!disc[next]) value = min(value, scc_DFS(next));
        else if(order_scc[next] == -1) value = min(value, disc[next]);
    }
    if(value == disc[curr]){
        vector<int> curr_scc;
        while(true){
            int target = S.top(); S.pop();
            curr_scc.push_back(target);
            order_scc[target] = scc_num;
            if(target == curr) break;
        }
        scc_num++;
        SCC.push_back(curr_scc);
    }
    return value;
}

// true -> false || false -> true
int oppo(int x){
    return x % 2 ? x+1 : x-1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        x = (x < 0) ? -x*2 : x*2 - 1;
        y = (y < 0) ? -y*2 : y*2 - 1;

        // ~x -> y
        adj[oppo(x)].push_back(y);
        // ~y -> x
        adj[oppo(y)].push_back(x);
    }

    memset(order_scc, -1, sizeof(order_scc));

    for(int i = 1; i <= 2*N; i++){
        if(!disc[i]) scc_DFS(i);
    }
    
    for(auto scc : SCC){
        for(int node : scc){
            for(int i : scc){
                if(oppo(node) == i){
                    cout << 0;
                    return 0;
                }
            }
        }
    }
     cout << 1;
}
