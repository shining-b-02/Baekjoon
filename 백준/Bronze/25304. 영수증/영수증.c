#include<stdio.h>
int main(){
	int x, n;
	int total = 0;
	
	scanf("%d %d", &x, &n);
	int pri[n];
	int b[n];
	for(int i=0; i<n; i++){
		scanf("%d %d",&pri[i], &b[i]);
		total += pri[i]*b[i];
	}
	if(x == total)
		printf("Yes");
	else
		printf("No");
		return 0;
}