#include <bits/stdc++.h>

using namespace std;

int m[101][101] = {0,};
vector<pair<int, char>> v;

char tail_dir[101][101] = {0, };

int curr_idx = 0;
int tail_idx = 0;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int ans = 0;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    int K; cin >> K;

    for(int i = 0; i < K; i++){
        int apple_y, apple_x;
        cin >> apple_y >> apple_x;
        m[apple_y][apple_x] = 1; // 사과 : 1
    }

    int L; cin >> L;

    for(int j = 0; j < L; j++){
        int time;
        char d;
        cin >> time >> d;
        v.push_back({time, d});
    }

    m[1][1] = 2; // 뱀 : 2
    int curr_y = 1, curr_x = 1;
    int tail_y = 1, tail_x = 1;
    int cnt = 0;
    int time = 0;

    while(true){
        time++;

        int ny = curr_y + dy[curr_idx];
        int nx = curr_x + dx[curr_idx];

        if(ny < 1 || ny > N || nx < 1 || nx > N || (m[ny][nx] == 2)){
            ans = time;
            break;
        }
        
        if(m[ny][nx] == 1){
            m[ny][nx] = 2;
            curr_y = ny;
            curr_x = nx;
        }
        else if(m[ny][nx] == 0){

            m[tail_y][tail_x] = 0;
            if(tail_dir[tail_y][tail_x] == 'D'){
                tail_idx++;
                if(tail_idx > 3) tail_idx = 0;
                tail_dir[tail_y][tail_x] = 0;
            }
            else if(tail_dir[tail_y][tail_x] == 'L'){
                tail_idx--;
                if(tail_idx < 0) tail_idx = 3;
                tail_dir[tail_y][tail_x] = 0;
            }
            tail_y += dy[tail_idx];
            tail_x += dx[tail_idx];

            m[ny][nx] = 2;
            curr_y = ny;
            curr_x = nx;
        }

        if(cnt < v.size() && time == v[cnt].first){
            if(v[cnt].second == 'D'){
                curr_idx++;
                if(curr_idx > 3) curr_idx = 0;
                tail_dir[curr_y][curr_x] = 'D';
            }
            else if(v[cnt].second == 'L'){
                curr_idx--;
                if(curr_idx < 0) curr_idx = 3;
                tail_dir[curr_y][curr_x] = 'L';
            }
            cnt++;
        }
    }

    cout << ans << "\n";

    return 0;
}