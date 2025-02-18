#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[9];
int visit[9];
int N, M;

void back(int current)
{
    int i;
    if (current == M+1) {
        for (i = 1; i <= M; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else {
        for (i = 1; i <= N; i++) {
            if (!visit[i]) {
                arr[current] = i;
                visit[i] = 1;
                back(current + 1);
                visit[i] = 0;
            }
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);

    back(1);

    return 0;
}