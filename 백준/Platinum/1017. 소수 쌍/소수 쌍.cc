// 모든 자연수들을 홀수 그룹과 짝수 그룹으로 나눈다.
// 1이 두 번 존재하지는 않으므로, 서로 다른 두 수를 더해서 나올 수 있는 소수인 수는 반드시 홀수여야만 하고(두 수를 더해서 2가 나오는 경우는 없으므로), 그러려면 반드시 홀수와 짝수를 더해야 한다.
// 홀수 그룹 정점 u와 짝수 그룹 정점 v가 있을 때 u+v가 소수일 때 둘 사이에 간선을 추가한 후 이분 매칭한다. 이때, 첫 번째 수와 가능한 모든 매칭을 다 해 보면서, 각각 최대 매칭이 N/2인지 판별하면 된다.

// 소수 쌍 - 플래티넘3
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;
int N, A[MAX], B[MAX];
vector<int> even, odd;
int first;
vector<int> ans;
vector<int> adj[MAX];
bool visited[MAX];

bool is_prime(int a, int b){
    int num = a + b;
    if(num < 2) return false;
    for(int i = 2; i*i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

bool DFS(int a){
    if(a == first) return false;
    visited[a] = true;
    for(int b : adj[a]){
        if(!B[b] || (!visited[B[b]] && DFS(B[b]))){
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;   
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        int num; cin >> num;
        if(i == 0) first = num;
        if(num % 2 == 0) even.push_back(num);
        else odd.push_back(num);
    }
    
    if(first % 2 == 0){
        for(int i : even)
            for(int j : odd)
                if(is_prime(i, j)) adj[i].push_back(j);
    }
    else{
        for(int i : odd)
            for(int j : even)
                if(is_prime(i, j)) adj[i].push_back(j);
    }
    for(int first_pair : adj[first]){
        
        fill(A, A+MAX, 0);
        fill(B, B+MAX, 0); 
        A[first] = first_pair;
        B[first_pair] = first;      
        int matched = 1;

        if(first % 2 == 0){
            for(int i : even){
                if(i == first) continue;
                fill(visited, visited+MAX, false);
                if(DFS(i)) matched++;
            }
        }
        else{
            for(int i : odd){
                if(i == first) continue;
                fill(visited, visited+MAX, false);
                if(DFS(i)) matched++;
            }
        }
        
        if(matched == N/2){
            ans.push_back(first_pair);
        } 
    }
    
    if(ans.empty()) cout << -1;
    else{
        sort(ans.begin(), ans.end());
        for(int i : ans) cout << i << " ";
    }
    
}
