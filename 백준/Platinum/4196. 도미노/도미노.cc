// 도미노 - 플래티넘4
// SCC DAG 에서 indegree가 0인 SCC의 개수
// 각 테스트 케이스마다 한 줄에 정수 하나를 출력한다. -> '\n' 대신 endl
// ios::sync_with_stdio(false)와 cin.tie(0)을 사용하면 입출력 성능이 향상되지만, 이로 인해 출력을 즉시 콘솔에 반영하지 않고 버퍼링하는 동작이 발생
//출력 버퍼를 강제로 비우는 flush를 호출 -> endl은 줄바꿈과 함께 자동으로 flush를 수행
#include <bits/stdc++.h> 
#define MAX 100001
using namespace std;

int N, M, cnt, SCC_num = 0, visited[MAX], node_scc[MAX], indegree[MAX];
vector<int> adj[MAX];
stack<int> S;

int DFS(int curr){
    visited[curr] = ++cnt;
    S.push(curr);

    int value = visited[curr];

    for(int next : adj[curr]){
        if(!visited[next]) value = min(value, DFS(next));
        else if(node_scc[next] == -1) value = min(value, visited[next]);
    }
    if(value == visited[curr]){
        while(true){
            int target = S.top(); S.pop();
            node_scc[target] = SCC_num;
            if(target == curr) break;
        }
        SCC_num++;
    }
    return value;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int T; cin >> T;

    while(T--){
        cin >> N >> M;

        SCC_num = 0; cnt = 0;
        for(int i = 1; i <= N; i++) adj[i].clear();
        fill(visited, visited+N+1, 0);
        fill(node_scc, node_scc+N+1, -1);
        fill(indegree, indegree+N+1, 0);

        for(int i = 0; i < M; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }

        for(int i = 1; i <= N; i++) if(!visited[i]) DFS(i);
            
        for(int i = 1; i <= N; i++){
            for(int j : adj[i]){
                if(node_scc[i] != node_scc[j]) indegree[node_scc[j]]++;
            }
        }

        int ans = 0;
        for(int i = 0; i < SCC_num; i++) if(!indegree[i]) ans++;
            
        cout << ans << endl;
    }
}