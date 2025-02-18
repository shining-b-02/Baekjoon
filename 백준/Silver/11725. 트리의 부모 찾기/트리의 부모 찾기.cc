#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100001];
int ans[100001] = {1};
int n;

void dfs(int node) {

    for (int i = 0; i < v[node].size(); i++) { 
        int k = v[node][i];
        if (!ans[k]) {
            ans[k] = node;
            dfs(k);
        }
    }
}

int main() {
    
    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}