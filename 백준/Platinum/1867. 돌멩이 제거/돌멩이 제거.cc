//돌멩이 제거 - 플래티넘3
//쾨니그 정리 --> 최대 매칭 == 최소 정점 커버
#include<bits/stdc++.h>

using namespace std;

const int MAX_V = 501;

int A[MAX_V], B[MAX_V];
vector<int> adj[MAX_V];
bool visited[MAX_V];

bool DFS(int row){
    visited[row] = true;
    for(int column : adj[row]){
        if(B[column] == -1 || (!visited[B[column]] && DFS(B[column]))){
            A[row] = column;
            B[column] = row;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int N, K; cin >> N >> K;

    for(int i = 0; i < K; i++){
        int row, column; cin >> row >> column;
        adj[row].push_back(column);
    }

    int matched = 0;
    fill(A, A+MAX_V, -1);
    fill(B, B+MAX_V, -1);

    for(int i = 1; i <= N; i++){
        fill(visited, visited+MAX_V, false);
        if(DFS(i)) matched++;
    }
    cout << matched;
}