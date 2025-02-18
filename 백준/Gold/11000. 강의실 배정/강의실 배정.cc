// 강의실 배정 - 골드5
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
priority_queue<int, vector<int>,greater<int>> pq;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int N; cin >> N;

    for(int i = 0; i < N; i++){
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    } 
    sort(v.begin(), v.end());
    pq.push(v[0].second);

    for(int i = 1; i < N; i++){
        if(pq.top() <= v[i].first){
            pq.pop();
            pq.push(v[i].second);
        }
        else{
            pq.push(v[i].second);
        }
    }
    cout << pq.size();
}