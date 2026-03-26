#include <bits/stdc++.h>
using namespace std;

int main(){

    long long ans = 0;

    int N; cin >> N;

    vector<int> v;

    for(int i = 0; i < N; i++){
        int temp; cin >> temp;
        v.push_back(temp);
    }

    int B, C; cin >> B >> C;

    vector<int>::iterator iter;
    for(iter = v.begin(); iter != v.end(); iter++){
        if(*iter > B){
            int remain = *iter - B;
            int temp = remain % C;

            if(!temp) ans += 1 + (remain / C);
            else ans += 1 + (remain / C) + 1;
        }
        else ans++;

        //cout << ans << "\n";
    }

    cout << ans << "\n";

    return 0;
}