#include <bits/stdc++.h>
using namespace std;

int sushi[30001];
bool check[3001];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int N, d, k, c; cin >> N >> d >> k >> c;

    for(int i = 0; i < N; i++) cin >> sushi[i];
    
    int ans = 0;
    for(int i = 0; i < N; i++){
        int flag = 0; // 중복초밥 개수
        int cuppon = 1;

        // 슬라이딩 윈도우
        for(int j = i; j < i + k; j++){
            if(check[sushi[j % N]]) flag++;
            else check[sushi[j % N]] = true;
            if(sushi[j % N] == c) cuppon = 0;
        }
        ans = max(ans, k - flag + cuppon);
        fill(check, check+3001, false);
    }
    cout << ans;
}
