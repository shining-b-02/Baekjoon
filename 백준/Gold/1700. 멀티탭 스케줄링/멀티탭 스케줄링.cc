#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int schedule[101]; // 기기 사용순서 저장 배열
int multitap[101]; // 현재 멀티탭에 꽂혀 있는 기기들 저장 배열

int main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int N, K;

	cin >> N >> K;
	if(N >= K){
		cout << 0;
		return 0;
	}

	for(int i = 0; i < K; i++){
		cin >> schedule[i];
	}

	int c_idx = 0; // 멀티탭에 꽂혀있는 기기 개수
	int o_idx = 0; // 현재 사용할 기기의 순서

// 플러그를 뽑지 않아도 꽂을 수 있는 최대한의 개수를 멀티탭에 꽂는다 (초기 멀티탭 세팅)
	while(c_idx < N){   
		if(find(multitap, multitap + N, schedule[o_idx]) == multitap + N){
			multitap[c_idx] = schedule[o_idx];
			c_idx++;
		} 
		o_idx++;
	}

	int ans = 0; // 멀티탭에서 기기 뽑는 횟수

	for(int i = o_idx; i < K; i++){ // 초기세팅 이후 남은 기기들 순서대로 처리
		int current = schedule[i];  // 현재 사용할 기기
		if(find(multitap, multitap + N, current) == multitap + N){   // 현재사용할 기기가 멀티탭에 꽂혀있지 않은경우
			pair<int, int> m = {INT_MIN, INT_MIN};  // 가장 나중에 사용할 기기 or 앞으로 사용하지 않는 기기를 저장할 변수
			for(int j = 0; j < N; j++){   // 멀티탭에 꽂힌 기기 중, 앞으로 사용하지 않거나 가장 나중에 사용할 기기를 찾는다
				pair<int, int> c;
				int pos = find(schedule + i, schedule + K, multitap[j]) - schedule; // 멀티탭에 꽂힌 기기 multitap[j]가 언제 사용되는지 pos에 저장
				if(pos == K) // 앞으로 사용되지 않는다
					c = {INT_MAX, j};
				else
					c = {pos, j}; // 앞으로 사용된다
				if(c.first > m.first) // 더 나중에 사용되거나 사용되지 않는 기기 선택
					m = c;
			}
			multitap[m.second] = current; // 선택된 기기를 멀티탭에서 빼고, 현재 사용할 기기를 꽂는다
			ans++; // 뽑는 횟수 증가
		}
	}
	cout << ans << '\n';
	return 0;
}