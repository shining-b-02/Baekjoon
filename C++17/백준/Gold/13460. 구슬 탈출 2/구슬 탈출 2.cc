#include <bits/stdc++.h>

using namespace std;

char board[11][11];
bool visited[11][11][11][11];

int directions[4][2] = {
    {0, 1}, // right
    {1, 0}, // down
    {0, -1}, // left
    {-1, 0} // up
};

struct State{
    int redY;
    int redX;
    int blueY;
    int blueX;
    int moves;
};

struct MoveResult{
    int y;
    int x;
    int dist;
    bool inHole;
};

MoveResult moveMarble(int startY, int startX, int dir, bool inhole){
    int y = startY;
    int x = startX;
    int dist = 0;

    while(board[y + directions[dir][0]][x + directions[dir][1]] != '#'){
        y += directions[dir][0];
        x += directions[dir][1];
        dist++;

        if(board[y][x] == 'O'){
            return {y, x, dist, true};
        }
    }
    return {y, x, dist, false};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int startRedY = 0;
    int startRedX = 0;
    int startBlueY = 0;
    int startBlueX = 0; 

    int N, M; cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            
            if(board[i][j] == 'R'){
                startRedY = i;
                startRedX = j;
                board[i][j] = '.';
            } else if(board[i][j] == 'B'){
                startBlueY = i;
                startBlueX = j;
                board[i][j] = '.';
            }
        }
    }

    queue<State> q;
    q.push({startRedY, startRedX, startBlueY, startBlueX, 0});
    visited[startRedY][startRedX][startBlueY][startBlueX] = true;

    while(!q.empty()){
        State current = q.front();
        q.pop();

        if(current.moves == 10) break;

        for(int dir = 0; dir < 4; dir++){
            MoveResult nextRed = moveMarble(current.redY, current.redX, dir, false);
            MoveResult nextBlue = moveMarble(current.blueY, current.blueX, dir, false);

            if(nextBlue.inHole) continue;

            if(nextRed.inHole){
                cout << current.moves + 1 << "\n";
                return 0;
            }

            if(nextRed.y == nextBlue.y && nextRed.x == nextBlue.x){
                if(nextRed.dist > nextBlue.dist){
                    nextRed.y -= directions[dir][0];
                    nextRed.x -= directions[dir][1];
                }
                else{
                    nextBlue.y -= directions[dir][0];
                    nextBlue.x -= directions[dir][1];
                }
            }

            if(visited[nextRed.y][nextRed.x][nextBlue.y][nextBlue.x]) continue;

            visited[nextRed.y][nextRed.x][nextBlue.y][nextBlue.x] = true;
            q.push({nextRed.y, nextRed.x, nextBlue.y, nextBlue.x, current.moves + 1});
        }
    }

    cout << -1 << "\n";
    return 0;    
}