#include <stdio.h>

int main()
{
	int i, j;
	int I, J;
	int arr_i[3] = {0,};
	int arr_j[3] = {0,};
	scanf("%d %d", &i, &j);
	
	arr_i[0] = (i%100)%10;
	arr_i[1] = ((i%100) - arr_i[0])/10;
	arr_i[2] = i/100;
	
	arr_j[0] = (j%100)%10;
	arr_j[1] = ((j%100) - arr_j[0])/10;
	arr_j[2] = j/100;
	
	I = arr_i[0]*100 + arr_i[1]*10 +arr_i[2];
	J = arr_j[0]*100 + arr_j[1]*10 +arr_j[2];
	
	if(I>J)
		printf("%d\n",I);
	else
		printf("%d\n",J);
	
	return 0;
}