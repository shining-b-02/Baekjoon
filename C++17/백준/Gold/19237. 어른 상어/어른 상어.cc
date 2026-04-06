#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};

struct SharkDirPrio {
    int p[5][4];
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<pair<int, int>> pos(M + 1, {-1, -1});
    vector<bool> alive(M + 1, false);

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> board[y][x];
            if (board[y][x] > 0) {
                int shark = board[y][x];
                pos[shark] = {y, x};
                alive[shark] = true;
            }
        }
    }

    vector<int> dir(M + 1);
    for (int shark = 1; shark <= M; shark++) {
        cin >> dir[shark];
    }

    vector<SharkDirPrio> priority(M + 1);
    for (int shark = 1; shark <= M; shark++) {
        for (int currDir = 1; currDir <= 4; currDir++) {
            for (int i = 0; i < 4; i++) {
                cin >> priority[shark].p[currDir][i];
            }
        }
    }

    vector<vector<int>> smellOwner(N, vector<int>(N, 0));
    vector<vector<int>> smellTime(N, vector<int>(N, 0));

    for (int shark = 1; shark <= M; shark++) {
        if (!alive[shark]) {
            continue;
        }
        int y = pos[shark].first;
        int x = pos[shark].second;

        smellOwner[y][x] = shark;
        smellTime[y][x] = K;
    }

    int aliveCount = M;
    int answer = 0;

    while (aliveCount > 1 && answer <= 1000) {
        answer++;

        vector<vector<int>> nextBoard(N, vector<int>(N, 0));
        vector<pair<int, int>> nextPos = pos;

        for (int shark = 1; shark <= M; shark++) {
            if (!alive[shark]) {
                continue;
            }
            int y = pos[shark].first;
            int x = pos[shark].second;

            int currDir = dir[shark];
            int moveDir = 0;
            int ny = -1;
            int nx = -1;

            for (int i = 0; i < 4; i++) {
                int candDir = priority[shark].p[currDir][i];
                int ty = y + dy[candDir];
                int tx = x + dx[candDir];

                if (ty < 0 || ty >= N || tx < 0 || tx >= N) {
                    continue;
                }
                if (smellTime[ty][tx] == 0) {
                    moveDir = candDir;
                    ny = ty;
                    nx = tx;
                    break;
                }
            }

            if (moveDir == 0) {
                for (int i = 0; i < 4; i++) {
                    int candDir = priority[shark].p[currDir][i];
                    int ty = y + dy[candDir];
                    int tx = x + dx[candDir];

                    if (ty < 0 || ty >= N || tx < 0 || tx >= N) {
                        continue;
                    }
                    if (smellOwner[ty][tx] == shark && smellTime[ty][tx] > 0) {
                        moveDir = candDir;
                        ny = ty;
                        nx = tx;
                        break;
                    }
                }
            }

            dir[shark] = moveDir;

            if (nextBoard[ny][nx] == 0) {
                nextBoard[ny][nx] = shark;
                nextPos[shark] = {ny, nx};
            } else if (nextBoard[ny][nx] < shark) {
                alive[shark] = false;
                aliveCount--;
            } else {
                int removed = nextBoard[ny][nx];
                alive[removed] = false;
                aliveCount--;
                nextBoard[ny][nx] = shark;
                nextPos[shark] = {ny, nx};
            }
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (smellTime[y][x] > 0) {
                    smellTime[y][x]--;
                    if (smellTime[y][x] == 0) {
                        smellOwner[y][x] = 0;
                    }
                }
            }
        }

        for (int shark = 1; shark <= M; shark++) {
            if (!alive[shark]) {
                continue;
            }
            int y = nextPos[shark].first;
            int x = nextPos[shark].second;
            
            smellOwner[y][x] = shark;
            smellTime[y][x] = K;
        }

        board = nextBoard;
        pos = nextPos;
    }

    if (answer > 1000) {
        cout << -1 << '\n';
    } else {
        cout << answer << '\n';
    }

    return 0;
}
