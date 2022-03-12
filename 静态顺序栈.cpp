#include <stdio.h>
#include <stdlib.h> 

#define MAXLENGTH 10

typedef struct {
	int	data[MAXLENGTH];
	int length;
}SqStack; 

void InitStack (SqStack * p) {
	p->length = -1; 
}
bool isEmpty (SqStack * p) {
	if (p->length == -1)
		return true;
	else
		return false;
}
void DestroyStack (SqStack * p) {
	free(p);
} 

bool Push (SqStack * p, int data) {
	if (p->length >= MAXLENGTH - 1)
		return false;
	p->data[++p->length] = data;
	return true;
}
bool Pop (SqStack * p) {
	if (isEmpty(p))
		return false;
	p->length--;
	return true; 
}
void GetTop (SqStack * p, int * e) {
	if (isEmpty(p))
		return;
	*e = p->data[p->length]; 
}
int StackLength (SqStack * p) {
	return p->length + 1;
}

int main () {
	SqStack S;
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
