#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
	int data;
	stackNode * next;
}Stack;

void InitStack (Stack * p) {
	p->next = NULL;
}
bool EmptyStack (Stack * p) {
	if (p->next == NULL)
		return true;
	else
		return false; 
}
void DestroyStack (Stack * p) {
	Stack * temp = p;
	void Pop (Stack * p); 
	while (p->next != NULL)
		Pop(p = p->next);
	free(temp); 
}

bool Push (Stack * p, int data) {
	Stack * temp;
	temp = (Stack *)malloc(sizeof(stackNode));
	if (temp == NULL)
		return false;
	temp->data = data;
	temp->next = p->next; 
	p->next = temp;
	return true;
}
void Pop (Stack * p) {
	stackNode * temp;
	temp = p->next->next;
	free(p->next);
	p->next = temp;
}
void GetTop (Stack * p, int * e) {
	*e = p->next->data;
} 
int StackLength (Stack * p) {
	int i;
	if (EmptyStack(p))
		return 0;
	for (i = 0; p->next != NULL; i++)
		p = p->next;
	return i;
} 


int main () {
	Stack S;
	int e; 
	InitStack(&S);
	Push(&S, 10);
	Push(&S, 11);
	GetTop(&S, &e);
	printf("当前栈顶内容为：%d\n", e);
	printf("当前栈长度为：%d\n", StackLength(&S));
	Pop(&S); 
	GetTop(&S, &e);
	printf("当前栈顶内容为：%d\n", e);
	printf("当前栈长度为：%d\n", StackLength(&S));
	DestroyStack(&S);
	return 0;	
}
