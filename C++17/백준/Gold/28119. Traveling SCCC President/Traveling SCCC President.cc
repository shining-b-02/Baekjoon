//Traveling SCCC President - 골드3
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int N, M, S, P[2001];
vector<tuple<int, int, int>> E;
vector<int> order;

int Find(int v){
    return P[v] == v ? v : P[v] = Find(P[v]);
}

bool Union(int v1, int v2){
    return Find(v1) != Find(v2) && (P[Find(v1)] = Find(v2), true);
}

int Kruskal(){
    int ret = 0;
    for(int i = 1; i <= N; i++) P[i] = i;
    sort(E.begin(), E.end());
    for(auto [time, v1, v2] : E){
        if(Union(v1, v2)) ret += time;
    }
    return ret;
}

int main(){
    ios:: sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> N >> M >> S;

    for(int i = 0; i < M; i++){
        int v1, v2, time; cin >> v1 >> v2 >> time;
        E.push_back(make_tuple(time, v1, v2));
    }
    for(int i = 0; i < N; i++){
        int v; cin >> v;
        order.push_back(v);
    }

    cout << Kruskal();
}