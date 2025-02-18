// 상어의 저녁식사 - 플래티넘3
#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 51;
bool visited[MAX_V];
int N, A[MAX_V], B[MAX_V];
vector<int> adj[MAX_V];
int stat[MAX_V][3];
int matched;

bool compare(int i, int j){
    return stat[i][0] >= stat[j][0] && stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2];
}

bool DFS(int shark){
    visited[shark] = true;
    for(int shark_pair : adj[shark]){
        if(B[shark_pair] == -1 || (!visited[B[shark_pair]] && DFS(B[shark_pair]))){
            A[shark] = shark_pair;
            B[shark_pair] = shark;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) cin >> stat[i][0] >> stat[i][1] >> stat[i][2];
    
    for(int i = 1; i <= N; i++){
        for(int j = i+1; j <= N; j++){
            
            if(compare(i, j)){
                adj[i].push_back(j);
            }
            else if(compare(j, i)){
                adj[j].push_back(i);
            }
        }
    }
    
    fill(A, A+MAX_V, -1);
    fill(B, B+MAX_V, -1);
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 2; j++){
            fill(visited, visited+N+1, false);
            if(DFS(i)) matched++;
        }
    }   
    cout << N - matched;
}