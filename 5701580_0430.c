#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	return -1;
}

void init_queue(QueueType *q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.\n");
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.\n");
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

element peek(QueueType* q) {
	if (is_empty(q)) {
		error("Queue is empty\n");
	}
	else {
		return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
	}
}

void queue_print(QueueType* q) {
	int i;
	printf("-----------------------------\n");
	printf("현재 큐의 상태: ");
	if (is_empty(q)) {
		error("큐가 비어있습니다.");
	}
	else {
		for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
			printf("%2d ", q->data[i]);
		}
		printf("%2d\n", q->data[i]);
	}
	printf("-----------------------------\n");
}

int main(void) {
	QueueType queue;
	element e;
	int choice;

	init_queue(&queue);
	
	while (1) {
		printf("1. 큐에 원소를 삽입\n");
		printf("2. 큐에서 원소를 삭제\n");
		printf("3. 큐의 원소를 출력\n");
		printf("4. 종료\n");
		printf("메뉴를 선택하세요: ");
		scanf_s("%d", &choice);
		
		switch (choice) {
		case 1:
			printf("큐에 삽입할 숫자를 입력하세요: ");
			scanf_s("%d", &e);
			enqueue(&queue, e);
			printf("\n");
			break;
		case 2:
			e = dequeue(&queue);
			printf("큐에서 삭제된 원소: %d\n\n", e);
			break;
		case 3:
			queue_print(&queue);
			break;
		case 4:
			exit(0);
		default:
			printf("잘못된 선택입니다.\n");
		}
	}

}