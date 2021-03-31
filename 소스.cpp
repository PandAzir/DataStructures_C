#include<stdio.h>
#define MAXSIZE 10
int queue[MAXSIZE];
int front = -1, rear = -1;
typedef int element;

int put(element e) {
	if (rear >= MAXSIZE - 1) {
		printf("초과");
		return(-1);
	}
	queue[++rear] = e;
}

int get(element e) {
	if (front <= 0) {
		printf("내용없음");
		return -1;
	}
	return queue[front++];
}

//void print_queue(void) {
//	int i;
//	for (i = front; i != rear; i = ++i % MAXSIZE)
//		printf("%-6d", queue[i]);
//}


void main(void)
{
	/*int i;
	init_queue();*/

	printf("put 5 4 3 2 1");
	put(5);
	put(4);
	put(3);
	put(2);
	put(1);

}