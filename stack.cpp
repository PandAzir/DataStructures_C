#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS  
#define MAX_STACK_SIZE 6
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

/* Stack */

/*
intput: 없음
output: 1(스택이 비었음), 0(스택에 수가 있음)
스택이 비었는지 아닌지 확인한다
*/
int is_empty()
{
	return (top == -1);
}

/*
input:없음
output: 1(top이 max_stack_size와 같을때),0(top이 max_stack_size와 다를때)
stack이 꽉차있는지 아닌지 확인
*/
int is_full()
{
	return(top == MAX_STACK_SIZE);
}

/*
input:e
output:없음
stack에 element e집어넣기
*/
void push(element e)
{
	//만약 stack is full이면
	if (is_full()) {
		printf("stack is full");
	}
	else stack[++top] = e;
}

/*
input:없음
output:stack 최상단의 값
*/
int pop()
{
	//만약 stack is empty이면
	if (is_empty()) {
		printf("stack is empty");
	}
	else return stack[top--];
}

/*
stack 내부값을 출력
*/
void print_stack() {
	for (int i = 0;i<top;i++) {
		printf("%d ",stack[i]);
	}
}
//
int main() {
	FILE* fp = fopen("./input.txt", "r");
	int num;
	for (int i = 0;i < MAX_STACK_SIZE; i++) {
		fscanf(fp, "%d", &num);
		//printf("\n");
		push(num);
		//printf("element is pushed. \n current stack : ");
		//print_stack();
		//printf("\n\n");
	}
	
	int temp = top;
	for (int i = 0; i <= temp; i++) {
		printf("%d ",pop());
	}
	scanf("%c");
	scanf("%c");
	fclose(fp);
	return 0;
}