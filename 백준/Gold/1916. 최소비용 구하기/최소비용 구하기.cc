#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;
int N, M, dist[10001], START, END;
vector<pair<int, int>> G[10001]; // 간선 정보

void Dijkstra(){
    for(int i = 1; i <= N; ++i) dist[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
    dist[START] = 0; pq.emplace(0, START); // == pq.push(make_pair(0, Start));
    while(!pq.empty()){
        pair<int, int> cur = pq.top(); pq.pop();
        int cur_cost = cur.first;
        int cur_node = cur.second;
        
        if(dist[cur_node] != cur_cost) continue;

        for(pair<int, int> next : G[cur_node]){
            int next_cost = next.first;
            int next_node = next.second;

            if(dist[next_node] > dist[cur_node] + next_cost){
                dist[next_node] = dist[cur_node] + next_cost;
                pq.emplace(dist[next_node], next_node);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int u, v, cost; cin >> u >> v >> cost;
        G[u].push_back(make_pair(cost, v));
    }
    cin >> START >> END;
    Dijkstra();
    cout << dist[END];
}