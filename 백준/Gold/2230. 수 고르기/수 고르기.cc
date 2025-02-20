#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
int arr[100001];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);

	int N, M; cin >> N >> M;

	for(int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr+N);

	int ans = INF;
	int en = 0;

	for(int st = 0; st < N; st++){
		while(en < N && arr[en] - arr[st] < M) en++;
		if(en == N) break;
		ans = min(ans, arr[en] - arr[st]);
	}
	cout << ans;
}