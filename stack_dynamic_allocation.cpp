#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct {
	element* data; //element타입의 데이터
	int capacity;	// 현재 stack의 크기
	int top; //stack의 최근값
} StackType;

void init_stack(StackType* s) 
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));

}
// is_empty
// stack이 비었는지 확인
// top == -1 이면 stack이 비어있음
int is_empty(StackType *s){
	if (s->top == -1) {
		printf("stack이 비었음");
		return 1;
	}
	else return 0;
	}

// is_full
// stack이 꽉찼는지 확인
// top == capacity -1 이면 stack이 꽉찼음
int is_full(StackType *s) {
	return(s->top == s->capacity - 1);
}
	
// push
// stack[++top] = e 
// 
void push(StackType *s , element e) {
	if (is_full(s)) {
		//capacity를 늘린다 capacity* sizeof(element e)
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
		printf("스택 공백 오류\n");
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


