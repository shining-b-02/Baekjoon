#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visited;
int cnt = 0;

bool check_2(int r, int c){ // 네 방향 모두 청소되지 않은 빈칸이 없는 경우 체크

    if((board[r + 1][c] == 1 || (!board[r + 1][c] && visited[r + 1][c])) && (board[r - 1][c] == 1 || (!board[r - 1][c] && visited[r - 1][c])) 
    && (board[r][c + 1] == 1 || (!board[r][c + 1] && visited[r][c + 1])) && (board[r][c - 1] == 1 || (!board[r][c - 1] && visited[r][c - 1])))
        return true;
    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;
    int r, c, d; cin >> r >> c >> d;

    board.resize(N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int temp; cin >> temp;
            board[i].push_back(temp);
        }
    }

    visited.resize(N, vector<bool>(M, false));

    while(true){

        if(board[r][c] == 0 && !visited[r][c]){ // 현재 칸이 청소되지 않은 경우
                    visited[r][c] = true;
                    cnt++;
        }

        if(check_2(r, c) ){

            int temp_y = 0, temp_x = 0; // 후진
            if(d == 0) temp_y++;
            else if(d == 1) temp_x--;
            else if(d == 2) temp_y--;
            else if(d == 3) temp_x++;

            if(r + temp_y < 0 || r + temp_y > N - 1 || c + temp_x < 0 || c + temp_x > M - 1 || 
                (board[r + temp_y][c + temp_x] == 1)) break; // 2-2 과정 (후진 할 수 없다면 종료)

            else{ // 2-1 과정
                r += temp_y; 
                c += temp_x;
                continue;
            }
        }
        if((r - 1 >= 0 && board[r - 1][c] == 0 && !visited[r - 1][c]) || (c + 1 < M && board[r][c + 1] == 0 && !visited[r][c + 1]) || 
        (r + 1 < N && board[r + 1][c] == 0 && !visited[r + 1][c]) || (c - 1 >= 0 && board[r][c - 1] == 0 && !visited[r][c - 1])){
            d = (d + 3) % 4; // 왼쪽으로 회전

            int temp_y = 0, temp_x = 0;
            if(d == 0) temp_y--;
            else if(d == 1) temp_x++;
            else if(d == 2) temp_y++;
            else if(d == 3) temp_x--;

            if(r + temp_y < 0 || r + temp_y > N - 1 || c + temp_x < 0 || c + temp_x > M - 1 || 
                (board[r + temp_y][c + temp_x] == 1) || visited[r + temp_y][c + temp_x]) continue; // 왼쪽 방향이 청소되지 않은 빈칸이 아니거나 벽인 경우

            else{ // 왼쪽 방향이 청소되지 않은 빈칸인 경우
                r += temp_y; 
                c += temp_x;
                continue;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}