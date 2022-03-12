#include <stdio.h>
#include <stdlib.h> 
#define MAXLENGTH 5
typedef struct{
	int * data;
	int length;
}database; 

bool InitList (database * L) {
	int * p;
	p = (int *)malloc(MAXLENGTH * sizeof(int));
	if(!p)
		return false;
	L->data = p;
	L->length = 0;
	free(p); 
	return true;
} 
void FreeList (database * L) {
	free(L->data); 
}

void ListAdd (database * L, int data) {
	int * dataLength = &L->length; 
	L->data[*dataLength] = data;
	L->length++;
} 

void ListEcho (database * L) {
	for (int i = 0; i < L->length; i ++) {
		printf("%d\n", L->data[i]);
	} 
}

bool ListInsert (database * L, int data, int place) {
	if (L->length + 1 > MAXLENGTH) 
		return false;
	if (place < 1 || place > L->length)
		return false;
	for (int j = L->length; j > place - 1; j--) 
		L->data[j] = L->data[j - 1];
	L->data[place - 1] = data;
	L->length++;
	return true;
} 


int main () {
	database L;
	if(!InitList(&L)) {
		printf("分配线性表内存失败，程序退出\n");
		exit(0);
	} 
	ListAdd(&L, 2); 
	ListAdd(&L, 3); 
	ListAdd(&L, 1); 
	ListAdd(&L, 5); 
	if (!ListInsert(&L, 10, 2))
		printf("插入线性表失败\n");
	ListEcho(&L);
	FreeList(&L);
	return 0;
}
