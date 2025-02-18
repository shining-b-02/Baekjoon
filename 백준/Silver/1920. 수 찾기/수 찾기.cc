#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> v1, v2;

int N, M;

int binary_s(int num) {
    int start = 0;
    int end = N - 1;
    int mid;

    while (start <= end) {
         mid = (start + end) / 2;

         if (v1[mid] == num) return 1;

         else if (v1[mid] < num) start = mid + 1;

         else if (v1[mid] > num)  end = mid - 1;
   
    }
    return 0;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v1.push_back(temp);
    }

    sort(v1.begin(), v1.end());

    cin >> M;

    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        v2.push_back(temp);
    }

    for (int i = 0; i < M; i++) {
        cout << binary_s(v2[i]) << '\n';
    }
    
    return 0;
}