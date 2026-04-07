#include <bits/stdc++.h>

using namespace std;

int N; 
int ans = 50000;
int total_people = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<vector<pair<int, int>>> A1(N + 1, vector<pair<int, int>>(N + 1));

    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            cin >> A1[r][c].first;
            A1[r][c].second = 0;
            total_people += A1[r][c].first;
        }
    }

    for(int x = 1; x < N - 1; x++){
        for(int y = 2; y < N; y++){ // 기준점 설정(x, y)

            for(int d1 = 1; d1 < N - 1; d1++){
                for(int d2 = 1; d2 < N - 1; d2++){ // 경계선 길이 설정

                    if (x + d1 + d2 > N) continue;
                    if (y - d1 < 1) continue;
                    if (y + d2 > N) continue;

                    vector<vector<pair<int, int>>> A(N + 1, vector<pair<int, int>>(N + 1));
                    vector<int> people(6, 0);

                    A = A1;

                    int y5 = y;
                    for(int x5 = x; x5 <= x + d1; x5++){ // 1번 경계선
                        A[x5][y5].second = 5;
                        y5--;
                    }

                    y5 = y;
                    for(int x5 = x; x5 <= x + d2; x5++){ // 2번 경계선
                        A[x5][y5].second = 5;
                        y5++;
                    }

                    y5 = y - d1;
                    for(int x5 = x + d1; x5 <= x + d1 + d2; x5++){ // 3번 경계선
                        A[x5][y5].second = 5;
                        y5++;
                    }

                    y5 = y + d2;
                    for(int x5 = x + d2; x5 <= x + d1 + d2; x5++){ // 4번 경계선
                        A[x5][y5].second = 5;
                        y5--;
                    }

                    for(int x1 = 1; x1 < x + d1; x1++){ // 1번 선거구
                        for(int y1 = 1; y1 <= y; y1++){
                            if(A[x1][y1].second == 5) break;
                            people[1] += A[x1][y1].first;
                        }
                    }

                    for(int x2 = 1; x2 <= x + d2; x2++){ // 2번 선거구
                        for(int y2 = N; y2 > y; y2--){
                            if(A[x2][y2].second == 5) break;
                            people[2] += A[x2][y2].first;
                        }
                    }

                    for(int x3 = x + d1; x3 <= N; x3++){ // 3번 선거구
                        for(int y3 = 1; y3 < y - d1 + d2; y3++){
                            if(A[x3][y3].second == 5) break;
                            people[3] += A[x3][y3].first;
                        }
                    }

                    for(int x4 = x + d2 + 1; x4 <= N; x4++){ // 4번 선거구
                        for(int y4 = N; y4 >= y - d1 + d2; y4--){
                            if(A[x4][y4].second == 5) break;
                            people[4] += A[x4][y4].first;
                        }
                    }

                    people[5] = total_people - people[1] - people[2] - people[3] - people[4];

                    int max_people = *max_element(people.begin() + 1, people.end());
                    int min_people = *min_element(people.begin() + 1, people.end());
                    int temp_ans = max_people - min_people;

                    if(ans > temp_ans) ans = temp_ans;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
