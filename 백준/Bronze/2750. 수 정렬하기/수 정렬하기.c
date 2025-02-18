#include<stdio.h>
int N, arr[1000001];

void quickSort(int arr[],int start, int end){
	if(start >= end) // 원소가 1개인 경우 그대로 리턴
		return;
	int pivot = start; // 피봇은 첫 번째 원소
	int i = start + 1, j = end, temp;
	
	while(i <= j){ // 엇갈릴 때까지 반복
		while(arr[i] <= arr[pivot])
			i++;
		while(arr[j] >= arr[pivot] && j > start)
			j--;
		if(i > j){
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		} // 엇갈린 상태면 피벗과 교체
		else{
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			
		}	
		
	}
	quickSort(arr, start, j-1);
	quickSort(arr, j+1 , end);
	
}

int main(){
	
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		scanf("%d",&arr[i]);
	}
	quickSort(arr,0,N-1);
	
	for(int j=0; j<N; j++){
		printf("%d\n",arr[j]);
	}
		return 0;
}