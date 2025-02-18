#include <stdio.h>

int main()
{
	int arr[9][9] = {0,};
	int max = 0;
	int I = 0, J = 0;
	
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j] > max){
				max = arr[i][j];
				I = i;
				J = j;
			}
		}
	}
	printf("%d\n", max);
	printf("%d %d", I+1, J+1);
	
	return 0;
}