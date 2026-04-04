#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board;
vector<int> command;

int dice[6] = {0, 0, 0, 0, 0, 0}; // top, north, east, west, south, bottom

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, x, y, K; cin >> N >> M >> x >> y >> K;

    for(int i = 0; i < N; i++){
        board.resize(N);
        for(int j = 0; j < M; j++){
            int num; cin >> num;
            board[i].push_back(num);
        }
    }

    for(int i = 0; i < K; i++){
        int cmd; cin >> cmd;
        command.push_back(cmd);
    }

    for(int i = 0; i < K; i++){
        int cmd = command[i];
        bool flag = false;

        switch (cmd) {
            case 1: // East
                if (y + 1 < M) {
                    flag = true;
                    y++;
                    // Rotate dice
                    int temp = dice[2];
                    dice[2] = dice[0];
                    dice[0] = dice[3];
                    dice[3] = dice[5];
                    dice[5] = temp;
                }
                break;
            case 2: // West
                if (y - 1 >= 0) {
                    flag = true;
                    y--;
                    // Rotate dice
                    int temp = dice[3];
                    dice[3] = dice[0];
                    dice[0] = dice[2];
                    dice[2] = dice[5];
                    dice[5] = temp;
                }
                break;
            case 3: // North
                if (x - 1 >= 0) {
                    flag = true;
                    x--;
                    // Rotate dice
                    int temp = dice[1];
                    dice[1] = dice[0];
                    dice[0] = dice[4];
                    dice[4] = dice[5];
                    dice[5] = temp;
                }
                break;
            case 4: // South
                if (x + 1 < N) {
                    flag = true;
                    x++;
                    // Rotate dice
                    int temp = dice[4];
                    dice[4] = dice[0];
                    dice[0] = dice[1];
                    dice[1] = dice[5];
                    dice[5] = temp;
                }
                break;
        }

        if(!flag) continue;
        
        // Update board and output top face of dice
        if (board[x][y] == 0) {
            board[x][y] = dice[5];
        } else {
            dice[5] = board[x][y];
            board[x][y] = 0;
        }
        cout << dice[0] << "\n";
    }

    return 0;
}