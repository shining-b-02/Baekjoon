#include <bits/stdc++.h>

using namespace std;

vector<pair<int ,int>> chicken;
vector<vector<pair<int, int>>> chicken_combi;

int N, M;

void combi(int depth, vector<pair<int, int>> chi){
    if(chi.size() == M){
        chicken_combi.push_back(chi);
        return;
    }
    for(int i = depth; i < chicken.size(); i++){
        chi.push_back(chicken[i]);
        combi(i + 1, chi);
        chi.pop_back();
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<vector<int>> city(N + 1, vector<int>(N + 1));
    vector<pair<int, int>> house;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> city[i][j];
            if(city[i][j] == 2) chicken.push_back({i, j});
            else if(city[i][j] == 1) house.push_back({i, j}); 
        }
    }

    vector<pair<int, int>> temp;
    combi(0, temp);

    int ans = 2000;

    for(int cb = 0; cb < chicken_combi.size(); cb++){
        int city_sum = 0;
        for(int h = 0; h < house.size(); h++){

            int chicken_distance = 101;
            int hy = house[h].first;
            int hx = house[h].second;

            for(int c = 0; c < M; c++){
                int cy = chicken_combi[cb][c].first;
                int cx = chicken_combi[cb][c].second;

                int temp_distance = abs(hy - cy) + abs(hx - cx);
                if(temp_distance < chicken_distance) chicken_distance = temp_distance;
            }
            city_sum += chicken_distance;
        }
        if(ans > city_sum) ans = city_sum;
    }

    cout << ans << "\n";

    return 0;
}