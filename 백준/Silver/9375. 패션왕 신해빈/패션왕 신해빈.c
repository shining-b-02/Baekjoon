#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int T, n, flag = 0;
	char cloth_name[21];
	char* cloth_type;
	char* cloth_arr[30];
	int numarr[30] = { 0, };
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int result = 1;
		int arrnum = 0;

		scanf("%d", &n);
		for (int j = 0; j < n; j++) {

			cloth_type = (char*)malloc(sizeof(char) * 21);
			scanf("%s %s", cloth_name, cloth_type);

			for (int k = 0; k < arrnum; k++) {
				if (strcmp(cloth_arr[k], cloth_type) == 0) {
					numarr[k]++;
					flag = 1;
					break;
				}
			}
			
			if (flag == 0) {
				numarr[arrnum] = 1;
				cloth_arr[arrnum] = cloth_type;
				arrnum++;
			}
			flag = 0;
		}
		for (int i = 0; i < arrnum; i++) {
			result *= (numarr[i] + 1);
		}
		printf("%d\n", result - 1);
	}


	return 0;
}