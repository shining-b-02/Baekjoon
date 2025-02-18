#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char* arr;
	int top;
}stack;

int empty(stack* pare)
{
	if(pare->top == -1)
		return 1;
	else
		return 0;
}

void push(stack* Pare, char data)
{
	Pare->top++;
	Pare->arr[Pare->top] = data;
}

void pop(stack* pare)
{
	pare->top--;
}

int main()
{
	int T;
	scanf("%d",&T);
	
	for(int i = 0; i < T; i++){
		stack pare;
		pare.top = -1;
		pare.arr = (char*)calloc(51, sizeof(char));
		
		char arr_temp[51] = {0,};
		scanf("%s",arr_temp);
		
		for(int j = 0; j < strlen(arr_temp); j++){
			if(arr_temp[j] == '('){
				push(&pare, '(');
			}
			else if(arr_temp[j] == ')'){
				if(empty(&pare)!=1){
					pop(&pare);
				}
				else{
					pare.top = 1;
					break;
				}
					
			}
		}
		if(pare.top==-1)
			printf("YES\n");
		else
			printf("NO\n");
		
		free(pare.arr);
	}
	return 0;
}