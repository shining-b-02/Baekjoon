// 플로이드 - 골드4
#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;
int n, m;
int dist[101][101];

void floyd(){

    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    cin >> n >> m;

    // 자긴노드에서 자기노드로 가는것은 0 나머지는 INF로 초기화
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dist[i][j] = i == j ? 0 : INF;
        }
    }

    for(int i = 1; i <= m; ++i){
        int s, e, w; cin >> s >> e >> w;
        dist[s][e] = min(dist[s][e], w);
    }

    floyd();

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(dist[i][j] == INF) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}