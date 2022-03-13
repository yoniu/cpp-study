#include <stdio.h>
#include <stdlib.h> 

typedef struct Queue{
	int data;
	struct Queue * next; 
}Queue;

typedef struct {
	Queue * front, * rear;
	int length; 
}LinkQueue;

void InitQueue (LinkQueue * p) {
	p->front = (Queue *)malloc(sizeof(Queue));
	p->front->next = NULL;
	p->rear = p->front;
	p->length = 0;
}
bool EmptyQueue (LinkQueue * p) {
	if (p->front == p->rear)
		return true;
	else
		return false;
}

bool EnQueue (LinkQueue * p, int data) {
	Queue * temp = (Queue *)malloc(sizeof(Queue));
	if (temp == NULL)
		return false; 
	temp->data = data;
	temp->next = NULL;
	p->rear->next = temp;
	p->rear = temp;
	p->length++;
	return true; 
}
bool DeQueue (LinkQueue * p, int * e) {
	Queue * q;
	if (p->front->next == NULL)
		return false;
	q = p->front->next;
	*e = q->data;
	p->front->next = q->next;
	if (p->front->next == p->rear)
		p->rear = p->front;
	free(q); 
	p->length--;
	return true; 
}
bool GetHead (LinkQueue * p, int * e) {
	if (EmptyQueue(p))
		return false;
	*e = p->front->next->data;
	return true;
}
void DestroyQueue (LinkQueue * p) {
	Queue * temp = p->front, * q;
	while(temp->next != NULL){
		q = temp->next->next;
		free(temp);
		temp = q; 
	} 
	free(p->front);
	free(p);
} 
int QueueLength (LinkQueue * p) {
	return p->length; 
} 


int main () {
	LinkQueue Q;
	int e;
	InitQueue(&Q); 
	EnQueue(&Q, 10);
	EnQueue(&Q, 11);
	EnQueue(&Q, 12);
	EnQueue(&Q, 13);
	EnQueue(&Q, 14);
	GetHead(&Q, &e);
	printf("当前队列头内容为：%d\n", e);
	printf("当前队列长度为：%d\n", QueueLength(&Q));
	DeQueue(&Q, &e); 
	printf("当前离队内容为：%d\n", e);
	GetHead(&Q, &e);
	printf("当前队列头内容为：%d\n", e);
	printf("当前队列长度为：%d\n", QueueLength(&Q));
	DeQueue(&Q, &e); 
	printf("当前离队内容为：%d\n", e);
	GetHead(&Q, &e);
	printf("当前队列头内容为：%d\n", e);
	printf("当前队列长度为：%d\n", QueueLength(&Q));
	DestroyQueue(&Q); 
	return 0;
}
