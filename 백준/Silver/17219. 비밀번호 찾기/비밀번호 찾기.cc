#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b){
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int N, M; cin >> N >> M;

    unordered_map<string, string> um;

    for(int i = 0; i < N; i++){
        string site, password; cin >> site >> password;
        um[site] = password;
    }

    for(int i = 0; i < M; i++){
        string site; cin >> site;
        cout << um[site] << '\n';
    }
}
