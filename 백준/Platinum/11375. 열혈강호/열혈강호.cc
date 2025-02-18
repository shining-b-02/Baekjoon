// 열혈강호 - 플래티넘4  --> 축사배정이랑 똑같은듯?
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;
int N, M, A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];

bool DFS(int person){
    visited[person] = true;
    for(int work : adj[person]){
        if(!B[work] || !visited[B[work]] && DFS(B[work])){
            A[person] = work;
            B[work] = person;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        int num; cin >> num;
        for(int j = 0; j < num; j++){
            int work; cin >> work;
            adj[i].push_back(work);
        }
    }

    int match = 0;
    for(int i = 1; i <= N; i++){
        fill(visited, visited+N, false);
        if(DFS(i)) match++;
    }
    cout << match;
}
