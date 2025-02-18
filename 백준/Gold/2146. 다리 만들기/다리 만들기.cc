#include <bits/stdc++.h>
using namespace std;

int n;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool vis[101][101];
int board[101][101];
int dist[101][101];

// out of bound cheack
bool OOB(int a, int b){
    return a < 0 || a >= n || b < 0 || b >= n;
}

//대륙들 구분
void island(){
    int island_number = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] || board[i][j] == 0) continue;
            queue<pair<int,int>> Q;
            Q.push({i,j});
            vis[i][j] = true;

            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                board[cur.first][cur.second] = island_number;
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if(OOB(nx, ny)) continue;
                    if(board[nx][ny] == 0 || vis[nx][ny]) continue; 
                    Q.push({nx,ny});
                    vis[nx][ny] = true;
                }
            }
            island_number++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    island();

    for(int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
    queue<pair<int,int>> Q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] != 0){
                Q.push({i, j});
                dist[i][j] = 0;
            } 
        }
    }

    int ans = 1e9;

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(OOB(nx, ny) || board[nx][ny] == board[cur.first][cur.second]) continue;
            if(board[nx][ny] != 0){
                ans = min(ans, dist[cur.first][cur.second] + dist[nx][ny]);
            }  
            else{
                board[nx][ny] = board[cur.first][cur.second];
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                Q.push({nx,ny});
            }
        }
    }
    cout << ans;
}