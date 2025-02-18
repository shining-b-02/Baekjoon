#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, a[1001], d[1001], p[1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }
    int pos = 1;
    for (int i = 1; i <= n; i++) if (d[i] > d[pos]) pos = i;
    cout << d[pos] << "\n";

    vector<int> t;
    for (int i = pos; i; i = p[i])t.push_back(a[i]);
    reverse(t.begin(), t.end());
    for (auto i : t) cout << i << " ";
   
    return 0;
}