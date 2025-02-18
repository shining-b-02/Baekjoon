#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(pair<pair<int, string>, int> a, pair<pair<int, string>, int> b) {
     if (a.first.first == b.first.first) return a.second < b.second;
    return a.first < b.first;
}

vector<pair<pair<int, string>, int> > v;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a;
        string b;
        cin >> a >> b;
        v.push_back(make_pair(make_pair(a, b), i));
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << v[i].first.first << ' ' << v[i].first.second << '\n';
    }

    return 0;
}