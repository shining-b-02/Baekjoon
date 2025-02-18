#include<stdio.h>
int main(){
	int a, b;
	int t;
	
	scanf("%d",&t);
	int A[t], B[t];
	
	for(int i=0; i<t; i++){
		scanf("%d %d",&A[i], &B[i]);
	}
	for(int j=0; j<t; j++){
		printf("Case #%d: %d\n",j+1, A[j]+B[j]);
	}
	
		return 0;
}