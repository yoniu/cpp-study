#include <stdio.h> 

#define MAXLENGTH 10

typedef struct {
	int data[MAXLENGTH];
	int front, rear; // 定义前后指针 
}Queue;

// 初始化队列 
void InitQueue (Queue * p) {
	p->front = 0;
	p->rear = 0; 
} 
int QueueLength (Queue * p) {
	return (p->rear - p->front + MAXLENGTH) % MAXLENGTH;
	/*
		队列长度分两段
		一段是 ( QueueSize - front )，另一段是 ( 0 + rear )
		加在一起队列长度为 ( rear - front + QueueSize) 
	*/
}
bool IsQueueFull (Queue * p) {
	if ((p->rear + 1) % MAXLENGTH == MAXLENGTH) 
		return true;
	else
		return false;
} 
void DestroyQueue () {
	// 
}

bool EnQueue (Queue * p, int data) {
	if (IsQueueFull(p))
		return false;
	p->data[p->rear] = data;
	p->rear = (p->rear + 1) % MAXLENGTH;
	return true; 
}
bool DeQueue (Queue * p, int * e) {
	if (p->front == p->rear) 
		return false;
	*e = p->data[p->front];
	p->front = (p->front + 1) % MAXLENGTH;
	return true; 
} 
bool GetHead(Queue * p, int * e) {
	*e = p->data[p->front];
	return false;
} 

int main () {
	Queue Q;
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
	DestroyQueue(); 
	return 0; 
}
