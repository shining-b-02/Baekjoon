#include<stdio.h>
int main(){
	
	int  result=0, arr[10]={0,};
	
	for (int i = 0; i < 10; i++) {
		scanf("%d",&arr[i]); 
		arr[i] = arr[i] % 42;
	}
	
	for (int i = 0; i < 10; i++) {
		int cnt = 0;
		for(int j = i+1; j<10; j++){
			if(arr[i] == arr[j])
				cnt++;
		}
		if(cnt == 0)
			result++;
	}
	printf("%d", result);
	
	return  0;
}