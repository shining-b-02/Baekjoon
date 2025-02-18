#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int graph[26][26];
int visit[26][26];
int que_x[2501];
int que_y[2501];

int nx[4] = { 1, 0, -1, 0 };
int ny[4] = { 0, 1, 0, -1 };
int front, rear, cnt;
int flag;
int house = 1;
int k;
int num[626];
/*
int compare(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b)
		return -1;
	else if (*(int*)a < *(int*)b)
		return 1;
	else
		return 0;
}
*/



void sort()
{
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - 1; j++) {
			if (num[j] > num[j + 1]) {
				int temp;
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
}

void bfs(int start_x, int start_y)
{
	if (visit[start_x][start_y] == 1 || !graph[start_x][start_y])
		return;
	flag = 1;
	visit[start_x][start_y] = 1;
	que_x[rear] = start_x;
	que_y[rear] = start_y;
	rear++;

	while (front < rear) {
		int x = que_x[front];
		int y = que_y[front];
		front++;
		int next_x, next_y;
		
		for (int i = 0; i < 4; i++) {
			next_x = x + nx[i];
			next_y = y + ny[i];

			if (!visit[next_x][next_y] && graph[next_x][next_y] == 1) {
				visit[next_x][next_y] = 1;
				que_x[rear] = next_x;
				que_y[rear] = next_y;
				rear++;
				house++;
			}
		}
	}
	cnt++;
	return;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bfs(i, j);
			if (flag == 1) {
				num[k++] = house;
				house = 1;
				flag = 0;
			}
		}
	}
	//qsort(num, k, sizeof(int), compare);

	sort();

	printf("%d\n", cnt);

	for (int i = 0; i < k; i++) {
		printf("%d\n", num[i]);
	}

	return 0;
}