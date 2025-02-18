#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long arr[91];

int main()
{
	int N;
	scanf("%d", &N);

	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i <= N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	printf("%lld", arr[N]);

	return 0;
}