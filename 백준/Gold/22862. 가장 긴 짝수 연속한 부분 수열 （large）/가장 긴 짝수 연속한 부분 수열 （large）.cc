// 가장 긴 짝수 연속한 부분 수열 (large)
#include <bits/stdc++.h>
using namespace std;

int s[1000001];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);

	int N, K; cin >> N >> K;

	for(int i = 0; i < N; i++) cin >> s[i];
	
	int st = 0, en = 0, ans = 0, del = 0;

	while(en < N){

		if(s[en] % 2 != 0) del++;

		while(del > K){
			if(s[st] % 2 != 0) del--;
			st++;
		}
		ans = max(ans, en - st - del + 1);
		en++;
	}
	cout << ans;
}