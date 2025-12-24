#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    long long arr[5001];
    long long N; cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    long long a=0, b = N-1;
    long long ptr = 0;

    sort(arr, arr+N);

    int ans_pab[3];
    long long ans = LLONG_MAX;
    while(ptr < N && arr[ptr] + arr[a] + arr[b] != 0){
        
        for(; a < b;){
            if(a == ptr) {
                a++;
                continue;
            }
            if(b == ptr) {
                b--;
                continue;
            }
            long long sum = arr[a] + arr[b] + arr[ptr];
            if(llabs(sum) < llabs(ans)) {
                ans = sum;
                ans_pab[0] = ptr;
                ans_pab[1] = a;
                ans_pab[2] = b;
            }
            if(sum < 0) {
                a++;
            } else {
                b--;
            }
        }
        ptr++;
        a = 0;
        b = N-1;
    }

    sort(ans_pab, ans_pab+3);

    cout << arr[ans_pab[0]] << " " << arr[ans_pab[1]] << " " << arr[ans_pab[2]] << "\n";

    return 0;
}