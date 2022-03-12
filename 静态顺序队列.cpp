#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 10

typedef struct {
	int data[MAXLENGTH];
	int length;
}Queue; 

void InitQueue (Queue * Q) {
	Q->length = -1;
}
bool EmptyQueue (Queue * Q) {
	if (Q->length == -1)
		return true;
	else
		return false;
}
void DestroyQueue (Queue * Q) {
	free(Q);
} 

bool EnQueue (Queue * Q, int data) {
	if (Q->length >= MAXLENGTH)
		return false;
	Q->data[++Q->length] = data;
	return true;
}
bool DeQueue (Queue * Q, int * e) {
	if (Q->length > -1) {
		if (Q->length != 0) {
			int temp = NULL; 
			* e = Q->data[0];
			for (int i = Q->length - 1; i >= 0; i--){
				if (temp == NULL) {
					temp = Q->data[i]; 
					Q->data[i] = Q->data[i + 1]; 
				} else {
					int tt = Q->data[i];
					Q->data[i] = temp; 
					temp = tt; 
				} 
			} 
			Q->length--; 
		} 
		return true;
	} else
		return false;
} 
bool GetHead (Queue * Q, int * e) {
	if (EmptyQueue(Q))
		return false;
	*e = Q->data[0]; 
	return true;
} 
int QueueLength (Queue * Q) {
	return Q->length + 1;
}

void EchoQueue (Queue * Q) {
	if (EmptyQueue(Q))
		return;
	printf("当前队列为：\n");
	for (int i = 0; i < Q->length + 1; i++)
		printf("%d\n", Q->data[i]);
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
	EchoQueue(&Q); 
	DestroyQueue(&Q); 
	return 0;
}
