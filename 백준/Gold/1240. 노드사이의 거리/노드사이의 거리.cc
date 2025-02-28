// 노드사이의 거리리
#include <bits/stdc++.h>
using namespace std;

int tree[1001][1001];
int visited[1001];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);

	int N, M; cin >> N >> M;

	for(int i = 0; i < N-1; i++){
		int a, b, d; cin >> a >> b >> d;
		tree[a][b] = d;
		tree[b][a] = d;
	}

	for(int i = 0; i < M; i++){
		int a, b; cin >> a >> b;

		queue<int> Q;
		Q.push(a);

		while(!Q.empty()){
			bool flag = false;
			int current = Q.front();
			Q.pop();

			for(int j = 1; j <= N; j++){
				if(tree[current][j] != 0 && visited[j] == 0){
					visited[j] = visited[current] + tree[current][j];
					Q.push(j);
				}
			}
		}
		cout << visited[b] << '\n';
		fill(visited, visited+1001, 0);
	}
}