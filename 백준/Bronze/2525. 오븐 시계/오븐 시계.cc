#include<stdio.h>
int main() {
	int A, B, C;

	scanf("%d %d\n%d", &A, &B, &C);
	int SB = B + C;
	if (SB >= 60) {
		SB = (B + C) % 60;
		A = (A + (B + C) / 60) % 24;
	}

	printf("%d %d", A, SB);
	return 0;
}
