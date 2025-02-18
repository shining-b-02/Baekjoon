//가장 큰 정사각형 - 골드4
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[1001][1001];
int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++){
            arr[i][j] = s[j - 1] - '0'; // 문자열을 정수형으로 변환
        }
    }
    int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(arr[i][j] == 1){
                    if(i == 1 || j == 1) dp[i][j] = 1;
                else dp[i][j] = min({dp[i - 1][j - 1],dp[i][j - 1], dp[i - 1][j]}) + 1;
                }
            ans = max(ans, dp[i][j]);
            }
        }
        cout << ans * ans; 
}