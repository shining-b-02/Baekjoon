// 앱 - 골드3
// cost를 배낭의 크기로 생각해서 푼다 (cost하나의 최대값은 100)
// 기본 배낭문제와 다른점은 배낭의 크기가 정해져 있지 않다. 따라서 비용의 상한값인 10000까지 계산한다.
#include <bits/stdc++.h>
using namespace std;

int memory[101], cost[101], dp[10001];
int N, M;

int main(){
    
    cin >> N >> M;

    for(int i = 1; i <= N; i++) cin >> memory[i];
    for(int i = 1; i <= N; i++) cin >> cost[i];
    
    // i == 앱 번호
    for(int i = 1; i <= N; i++){
        // j == 비용(배낭)
        for(int j = 10000; j >= 0; j--){
            // j만큼의 비용으로 확보할 수 있는 최대 메모리 계산
            if(j >= cost[i]) dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
        }
    }

    int cost = 0;

    // M이상의 메모리를 확보할 수 있는 최소 비용을 찾음
    while(dp[cost] < M) cost++;
    cout << cost;
}