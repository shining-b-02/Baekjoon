#include <bits/stdc++.h>

using namespace std;

bool visited[8][8][8][8][8][8] = {false, };

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int ans = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;

    vector<vector<int>> m(N, vector<int>(M));
    vector<pair<int, int>> virus;

    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            cin >> m[y][x];
            if(m[y][x] == 2) virus.push_back(make_pair(y, x));
        }
    }

    for(int y1 = 0; y1 < N; y1++){
        for(int x1 = 0; x1 < M; x1++){

            if(m[y1][x1] != 0) continue;

            for(int y2 = 0; y2 < N; y2++){
                for(int x2 = 0; x2 < M; x2++){

                    if(m[y2][x2] != 0) continue;

                    for(int y3 = 0; y3 < N; y3++){
                        for(int x3 = 0; x3 < M; x3++){

                            if(m[y3][x3] != 0) continue;

                            if(y1 == y2 && x1 == x2) continue;
                            if(y1 == y3 && x1 == x3) continue;
                            if(y2 == y3 && x2 == x3) continue;
                            
                            if(visited[y1][x1][y2][x2][y3][x3]) continue;

                            visited[y1][x1][y2][x2][y3][x3] = true;

                            vector<vector<int>> temp_m(N, vector<int>(M));
                            temp_m = m;

                            temp_m[y1][x1] = 1;
                            temp_m[y2][x2] = 1;
                            temp_m[y3][x3] = 1;

                            queue<pair<int, int>> q;

                            for(int v = 0; v < virus.size(); v++){
                                q.push(virus[v]);
                            }

                            while(!q.empty()){
                                int cur_y = q.front().first;
                                int cur_x = q.front().second;
                                q.pop();

                                for(int dir = 0; dir < 4; dir++){
                                    int ny = cur_y + dy[dir];
                                    int nx = cur_x + dx[dir];

                                    if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                                    if(temp_m[ny][nx] == 1 || temp_m[ny][nx] == 2) continue;
                                    else{
                                        temp_m[ny][nx] = 2;
                                        q.push({ny, nx});
                                    }
                                }
                            }

                            int temp_ans = 0;
                            for(int r = 0; r < N; r++){
                                for(int c = 0; c < M; c++){
                                    if(temp_m[r][c] == 0) temp_ans++;
                                }
                            }
                            if(temp_ans > ans) ans = temp_ans;

                        }
                    }
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}