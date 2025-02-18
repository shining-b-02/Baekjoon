// Strongly Connected Component - 플래티넘5
#include<bits/stdc++.h>
#define MAX 10001
using namespace std;

int SCC_num, cnt, dfs_node[MAX], order_scc[MAX];
vector<int> adj[MAX];
vector<vector<int>> SCC;
stack<int> S;

int DFS(int curr){

    dfs_node[curr] = ++cnt;
    S.push(curr);
    int value = dfs_node[curr];

    for(int next : adj[curr]){
        if(!dfs_node[next]) value = min(value, DFS(next));
        else if(!order_scc[next]) value = min(value, dfs_node[next]);
    }
    if(value == dfs_node[curr]){
        vector<int> curr_scc;
        while(true){
            int target = S.top(); S.pop();
            curr_scc.push_back(target);
            order_scc[target] = value;
            if(target == curr) break;
        }
        SCC_num++;
        sort(curr_scc.begin(), curr_scc.end());
        SCC.push_back(curr_scc);
    }

    return value;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int V, E; cin >> V >> E;

    for(int i = 0; i < E; i++){
        int A, B; cin >> A >> B;
        adj[A].push_back(B);
    }

    for(int i = 1; i <= V; i++){
        if(!dfs_node[i]) DFS(i);
    }
    sort(SCC.begin(), SCC.end());

    cout << SCC_num << '\n';
    for(vector<int> scc : SCC){
        for(int node : scc){
            cout << node << " ";
        }
        cout << -1 << '\n';
    }
}