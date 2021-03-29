#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct {
	element* data; //elementŸ���� ������
	int capacity;	// ���� stack�� ũ��
	int top; //stack�� �ֱٰ�
} StackType;

void init_stack(StackType* s) 
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));

}
// is_empty
// stack�� ������� Ȯ��
// top == -1 �̸� stack�� �������
int is_empty(StackType *s){
	if (s->top == -1) {
		printf("stack�� �����");
		return 1;
	}
	else return 0;
	}

// is_full
// stack�� ��á���� Ȯ��
// top == capacity -1 �̸� stack�� ��á��
int is_full(StackType *s) {
	return(s->top == s->capacity - 1);
}
	
// push
// stack[++top] = e 
// 
void push(StackType *s , element e) {
	if (is_full(s)) {
		//capacity�� �ø��� capacity* sizeof(element e)
		s->capacity *= 2;
		s->data =
			(element*)realloc(s->data,s->capacity * sizeof(element));
	} 
	s->data[++(s->top)] = e;
}

// pop
// return stack[top--]
element pop(StackType *s) {
	if (is_empty(s)) {
		printf("���� ���� ����\n");
	}
	else return s->data[(s->top--)];
}

// main
int main (){
	StackType s;
	init_stack(&s);
	push(&s,1);
	push(&s,2);
	push(&s, 234);
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	free(s.data);
	return(0);
}


