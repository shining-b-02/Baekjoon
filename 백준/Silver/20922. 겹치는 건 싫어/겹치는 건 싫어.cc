// 겹치는 건 싫어 - 20922
#include <bits/stdc++.h>
using namespace std;

int arr[200001];
int check[100001];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);

	int N, K; cin >> N >> K;

	for(int i = 0; i < N; i++) cin >> arr[i];
	
	int ans = 1;
	int cur = 1;
	int st = 0, en = 0;
	check[arr[en]]++;
	en++;
	ans++;

	while(st < en){
		if(check[arr[en]] < K && en < N){
			check[arr[en]]++;
			en++;
			cur++;
		}
		else{
			check[arr[st]]--;
			st++;
			cur--;
		}
		ans = max(ans, cur);
		if(en < N && st == en){
			check[arr[st]]++;
			en++;
			cur++;
		} 
	}
	cout << ans;
}