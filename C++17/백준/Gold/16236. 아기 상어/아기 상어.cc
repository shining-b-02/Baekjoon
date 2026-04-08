#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int time_ans = 0;
int fish_num = 0;
int eat_num = 0;

struct shark{
    int y;
    int x;
    int size;
    int dist;
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<vector<int>> space(N, vector<int> (N));

    shark initial_shark;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> space[i][j];
            if(space[i][j] == 9){   
                initial_shark.y = i;
                initial_shark.x = j;
                initial_shark.size = 2;
            } // 아기상어 초기값 저장
            else if(space[i][j] >= 1 && space[i][j] <= 6) fish_num++;
        }
    }

    while(fish_num != 0){ // 물고기 다 먹을 때 까지 반복

        queue<shark> q;
        q.push({initial_shark.y, initial_shark.x, initial_shark.size, 0});

        // bfs로 가장 가까운 물고기 찾기
        vector<pair<int, int>> temp(401, {401, 401});
        vector<vector<bool>> visited(N, vector<bool> (N, false));
        while(!q.empty()){

            int curr_y = q.front().y;
            int curr_x = q.front().x;
            int curr_size = q.front().size;
            int curr_dist = q.front().dist;
            
            q.pop();

            for(int dir = 0; dir < 4; dir++){

                int ny = curr_y + dy[dir];
                int nx = curr_x + dx[dir];

                if(ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] == true) continue;

                if(space[ny][nx] == 0 || space[ny][nx] == curr_size){
                    q.push({ny, nx, curr_size, curr_dist + 1});
                    visited[ny][nx] = true;
                } 
                else if(space[ny][nx] > 0 && space[ny][nx] <= 6 && space[ny][nx] < curr_size){
                    if(temp[curr_dist + 1].first > ny){
                        temp[curr_dist + 1] = {ny, nx};
                        visited[ny][nx] = true;
                    }
                        
                    else if(temp[curr_dist + 1].first == ny && temp[curr_dist + 1].second > nx){
                        temp[curr_dist + 1] = {ny, nx};
                        visited[ny][nx] = true;
                    }     
                }
            }
        }
        bool flag = false;
        for(int i = 0; i < N * N; i++){
            if(temp[i].first < 401){
                int y = temp[i].first;
                int x = temp[i].second;

                space[initial_shark.y][initial_shark.x] = 0;

                initial_shark.y = y;
                initial_shark.x = x;

                eat_num++;
                if(initial_shark.size == eat_num){
                    initial_shark.size++;
                    eat_num = 0;
                } 
                fish_num--;
                time_ans += i;
                space[y][x] = 0;
                flag = true;
                break;
            }
        }
        if(!flag) break;
    }

    cout << time_ans << "\n";
    return 0;
}