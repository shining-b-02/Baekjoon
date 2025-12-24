#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    int arr[2000100];
    arr[0] = 0;
    arr[1] = 2;
    int k = 2;

    for(int i = 3; i <= N; i++){
        int j = 2;
        bool prime = true;
        while(j < sqrt(i) + 1){
            if(i % j == 0){
                prime = false;
                break;
            }
            j++;
        }
        if(prime){
            arr[k] = i + arr[k-1];
            k++;
        } 
    }

    int ptr1 = 0, ptr2 = 1;
    int ans = 0;

    //for(int i = 0; i < k; i++) cout << arr[i] << " ";
    //cout << "\n";

    while(ptr1 < ptr2){
        if(arr[ptr2] - arr[ptr1] == N){
            ans++;
            ptr1++;
            ptr2++;
        } else if(arr[ptr2] - arr[ptr1] < N){
            ptr2++;
        } else {
            ptr1++;
        }
    }
    cout << ans << "\n";
    return 0;
}