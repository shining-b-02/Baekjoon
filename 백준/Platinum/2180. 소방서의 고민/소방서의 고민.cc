//소방서의 고민 - 플래티넘5
#include <iostream>
#include <algorithm>
using namespace std;

pair<int , int> A[200001];

// b/a가 작은순으로 오름차순 정렬을 한다
//a가 0이면 제일 뒤로 보낸다
//b가 모두 0인 경우 a가 더 큰쪽을 앞으로 보낸다

//compare()의 첫번째 파라미터 : 뒤 요소
//compare()의 두번째 파라미터 : 앞 요소
//true 반환 -> 정렬한다
//false 반환 -> 정렬하지 않는다
bool compare(const pair<int ,int> a, const pair<int, int> b){
    
    if(!a.first) return false;
    else if(!b.first) return true;
    else if(!a.second && !b.second) return a.first < b.first;

    return a.second*b.first < a.first*b.second;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> A[i].first >> A[i].second;
    }

    sort(A, A+n, compare);     
    
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += A[i].first * ans;
        ans += A[i].second;
        ans %= 40000;
    }

    cout << ans;
}