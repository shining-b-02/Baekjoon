#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    int t;
    cin >> t;

    while (t--) {
        bool is_exit = false;
        int w, h;
        cin >> w >> h;

        vector<string> building(h);
        vector<vector<int>> fire_dist(h, vector<int>(w, -1)); // 불 전파 시간
        vector<vector<int>> sang_dist(h, vector<int>(w, -1)); // 상근 이동 시간

        // 건물 지도 입력
        for (int i = 0; i < h; i++) {
            cin >> building[i];
        }

        queue<pair<int, int>> fire_queue; // 불의 BFS 큐
        queue<pair<int, int>> sang_queue; // 상근의 BFS 큐

        // 불과 상근의 초기 위치 저장
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (building[i][j] == '*') {
                    fire_queue.push({i, j});
                    fire_dist[i][j] = 0;
                }
                if (building[i][j] == '@') {
                    sang_queue.push({i, j});
                    sang_dist[i][j] = 0;
                }
            }
        }

        // 불의 전파 BFS
        while (!fire_queue.empty()) {
            auto [x, y] = fire_queue.front();
            fire_queue.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (fire_dist[nx][ny] >= 0 || building[nx][ny] == '#') continue;

                fire_dist[nx][ny] = fire_dist[x][y] + 1;
                fire_queue.push({nx, ny});
            }
        }

        // 상근의 이동 BFS
        while (!sang_queue.empty() && !is_exit) {
            auto [x, y] = sang_queue.front();
            sang_queue.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                // 탈출 조건
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    cout << sang_dist[x][y] + 1 << '\n';
                    is_exit = true;
                    break;
                }
                if (sang_dist[nx][ny] >= 0 || building[nx][ny] == '#') continue;
                if (fire_dist[nx][ny] != -1 && fire_dist[nx][ny] <= sang_dist[x][y] + 1) continue;

                sang_dist[nx][ny] = sang_dist[x][y] + 1;
                sang_queue.push({nx, ny});
            }
        }

        if (!is_exit) cout << "IMPOSSIBLE\n";
    }

    return 0;
}
