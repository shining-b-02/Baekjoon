// K번째 최단경로 찾기 - 플래티넘4
#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;
int n, m, k;
priority_queue<int, vector<int>> dist[10001]; // dist를 우선순위 큐로 만드는것이 핵심!
vector<pair<int, int>> G[10001]; 

void Dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
    dist[1].push(0); pq.emplace(0, 1); 
    while(!pq.empty()){
        pair<int, int> cur = pq.top(); pq.pop();
        int cur_cost = cur.first;
        int cur_node = cur.second;

        for(pair<int, int> next : G[cur_node]){
            int next_cost = next.first;
            int next_node = next.second;
            if(dist[next_node].size() < k){
                dist[next_node].push(cur_cost + next_cost);
                pq.emplace(cur_cost + next_cost, next_node);
            }
            else if(dist[next_node].top() > cur_cost + next_cost){
                dist[next_node].pop();
                dist[next_node].push(cur_cost + next_cost);
                pq.emplace(cur_cost + next_cost, next_node);
            }        
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i){
        int u, v, cost; cin >> u >> v >> cost;
        G[u].push_back(make_pair(cost, v));
    }
    Dijkstra();
    for(int i = 1; i <= n; ++i){
        if(dist[i].size() < k) cout << -1 << '\n';
        else cout << dist[i].top() << '\n';
    }
}