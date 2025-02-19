#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b){
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int K, L; cin >> K >> L;

    unordered_map<string, int> M;

    for(int i = 0; i < L; i++){
        string s; cin >> s;
        M[s] = i;
    }

    vector<pair<string, int>> v;
    for(auto i : M) v.push_back(i);

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < min(K, (int)v.size()); i++) cout << v[i].first << '\n';
}
