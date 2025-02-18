#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int N, M;
int arr[8];

void find(int num, int last) {
	int i;
	if (num == M) {
		for (i = 0; i < M; i++)
			printf("%d ", arr[i] + 1);
		printf("\n");
		find(num + 1, i + 1);
	}
	else {
		for (i = last; i < N; i++) {
			arr[num] = i;
			find(num + 1, i + 1);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	find(0, 0);
	return 0;
}