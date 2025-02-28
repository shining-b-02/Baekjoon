// 최소 스패닝 트리 - 골드4
#include <bits/stdc++.h>

using namespace std;

long long planet[1001][1001];
long long N, P[1010];                // p[] --> 각노드의 부모노드 배열
vector<tuple<long long, long long, long long>> edge; // {비용, 정점1, 정점2}로 저장

long long Find(long long v){ return v == P[v] ? v : P[v] = Find(P[v]); }

bool Union(long long v1, long long v2){ return Find(v1) != Find(v2) && (P[Find(v1)] = Find(v2), true); }
// 부모가 같은지 확인 > 부모가 같다면 같은 트리안에 있음 > 합칠 시 사이클 발생 > false 반환

long long Kruskal()
{
    long long ret = 0;
    for (int i = 1; i <= N; i++)
        P[i] = i;                   // union-find 초기화
    sort(edge.begin(), edge.end()); // 간선 오름차순 정렬
    for (auto [cost, v1, v2] : edge)
        if (Union(v1, v2))                        
            ret += cost;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> planet[i][j];
            if(i != j){
                edge.push_back(make_tuple(planet[i][j], i, j)); // 가중치 기준으로 오름차순 정렬하기 때문에 가중치를 첫번째로 넣음
            }
        }
    }
    cout << Kruskal();
}