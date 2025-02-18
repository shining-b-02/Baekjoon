// 축구 전술 - 플래티넘4
// scc로 묶는 과정을 거치면 자연스럽게 위상정렬이 된다(order_scc[]의 반대순서) -> 4196(도미노)와 마찬가지
// indegree[]가 0인 scc가 한개만 존재할 때 모든 구역을 돌 수 있다.

#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
vector<int> adj[MAX];
vector<vector<int>> SCC;
int scc_num, cnt, disc_node[MAX], order_scc[MAX], indegree[MAX];
stack<int> S;

int DFS(int curr){
    disc_node[curr] = ++cnt;
    S.push(curr);

    int value = disc_node[curr];

    for(int next : adj[curr]){
        if(!disc_node[next]) value = min(value, DFS(next));
        else if(order_scc[next] == -1) value = min(value, disc_node[next]);
    }
    if(value == disc_node[curr]){
        vector<int> curr_scc;
        while(true){
            int target = S.top(); S.pop();
            curr_scc.push_back(target);
            order_scc[target] = scc_num;
            if(target == curr) break;
        }
        scc_num++;
        sort(curr_scc.begin(),curr_scc.end());
        SCC.push_back(curr_scc);
    }
    return value;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int T; cin >> T;
    while(T--){
        scc_num = 0; cnt = 0;
        memset(order_scc, -1, sizeof(order_scc));
        memset(disc_node, 0, sizeof(disc_node));
        memset(indegree, 0, sizeof(indegree));
        for(int i = 0; i < MAX; i++) adj[i].clear();
        SCC.clear();

        int N, M; cin >> N >> M;
        for(int i = 0; i < M; i++){
            int A, B; cin >> A >> B;
            adj[A].push_back(B);
        }

        for(int i = 0; i < N; i++) if(!disc_node[i]) DFS(i);
            
        for(int i = 0; i < N; i++){
            for(int j : adj[i]){
                if(order_scc[i] != order_scc[j]) indegree[order_scc[j]]++;
            }
        }
        
        int temp = 0;
        for(int i = 0; i < scc_num; i++) if(!indegree[i]) temp++;

        if(temp == 1){
            vector<int> ans;
            for(int i = 0; i < N; i++){
                if(order_scc[i] == scc_num - 1) ans.push_back(i);
            }
            sort(ans.begin(), ans.end());
            for(int i : ans) cout << i << '\n';
        }
        else cout << "Confused" << '\n';
        cout << '\n';
    }
    
}