// 열혈강호 3 - 플래티넘3
#include<bits/stdc++.h>

using namespace std;

const int MAX_V = 1001;

int A[MAX_V], B[MAX_V];
vector<int> adj[MAX_V];
bool visited[MAX_V];

bool DFS(int a){
    visited[a] = true;
    for(int b : adj[a]){
        if(B[b] == -1 || (!visited[B[b]] && DFS(B[b]))){
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int N, M, K; cin >> N >> M >> K;

    for(int i = 1; i <= N; i++){
        int temp; cin >> temp;
        for(int j = 0; j < temp; j++){
            int work; cin >> work;
            adj[i].push_back(work);
        }
    }

    int matched = 0;
    fill(A, A+MAX_V, -1);
    fill(B, B+MAX_V, -1);

    for(int i = 1; i <= N; i++){
        fill(visited, visited+MAX_V, false);
        if(DFS(i)) matched++;
    }

    for(int i = 1; i <= N; i++){
        fill(visited, visited+MAX_V, false);
        if(DFS(i)){
            matched++;
            K--;
        }
        if(!K) break; 
    }
    cout << matched;
}