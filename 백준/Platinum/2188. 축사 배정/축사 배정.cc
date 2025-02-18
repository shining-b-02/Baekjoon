// 축사 배정 - 플래티넘4
// 이분매칭으로 푼 버전
#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 201;
int N, M, A[MAX_V], B[MAX_V]; // 각 정점이 매칭된 반대편 정점번호 
bool visited[MAX_V];
vector<int> adj[MAX_V];

bool DFS(int cow){
    visited[cow] = true;
    for(int house : adj[cow]){
        // 반대편이 매칭되지 않았거나, 매칭되어 있었지만 원래 매칭되어 있던 정점을 다른 정점과 매칭시킬 수 있으면 성공
        if(!B[house] || !visited[B[house]] && DFS(B[house])){
            A[cow] = house;
            B[house] = cow;
            return true;
        }
    }
    // 매칭 실패
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        int num; cin >> num;
        for(int j = 0; j < num; j++){
            int house; cin >> house;
            adj[i].push_back(house);
        }
    }

    int match = 0;
    
    for(int i = 1; i <= N; i++){
        fill(visited, visited+N, false);
        if(DFS(i)) match++;
    }

    cout << match;
}
