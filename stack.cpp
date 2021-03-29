#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS  
#define MAX_STACK_SIZE 6
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

/* Stack */

/*
intput: ����
output: 1(������ �����), 0(���ÿ� ���� ����)
������ ������� �ƴ��� Ȯ���Ѵ�
*/
int is_empty()
{
	return (top == -1);
}

/*
input:����
output: 1(top�� max_stack_size�� ������),0(top�� max_stack_size�� �ٸ���)
stack�� �����ִ��� �ƴ��� Ȯ��
*/
int is_full()
{
	return(top == MAX_STACK_SIZE);
}

/*
input:e
output:����
stack�� element e����ֱ�
*/
void push(element e)
{
	//���� stack is full�̸�
	if (is_full()) {
		printf("stack is full");
	}
	else stack[++top] = e;
}

/*
input:����
output:stack �ֻ���� ��
*/
int pop()
{
	//���� stack is empty�̸�
	if (is_empty()) {
		printf("stack is empty");
	}
	else return stack[top--];
}

/*
stack ���ΰ��� ���
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