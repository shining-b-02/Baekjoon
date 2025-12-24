// Subsequence
#include <bits/stdc++.h>
using namespace std;

int arr[100001], sum[100001];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int N, S; cin >> N >> S;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        sum[i] = arr[i] + sum[i - 1];
    }
    int ans = N+1, idx_i = 0, idx_j = 1;
    while(idx_i <= N){
        if(sum[idx_j] - sum[idx_i] < S) idx_j++;
        else{
            ans = min(ans, idx_j - idx_i);
            idx_i++;
        }
    }
    if(ans == N+1) cout << 0;
    else cout << ans;
}