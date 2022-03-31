#include <stdio.h>
#define MAX 7

void InsertSort (int data[]) {
	// ֱ�Ӳ����㷨 
	// ʱ�临�Ӷȣ�O(n^2) 
	int i, j, temp;
	for (i = 1; i <= MAX; i++) {
		if (data[i] < data[i-1]) {
			temp = data[i];
			for (j = i - 1; j >= 0 && temp < data[j]; j--) 
				data[j + 1] = data[j];
			data[j + 1] = temp;
		}
	} 
}
void SellSort (int data[]) {
	// ϣ�������㷨
	// ʱ�临�Ӷȣ��޷�����
	int i, j, n, temp;
	n = MAX;
	do{
		n = n / 2;
		for (i = n; i <= MAX; i++) {
			if (data[i] < data[i - n]) {
				temp = data[i];
				for (j = i - n; j >= 0 && temp < data[j]; j -= n)
					data[j + n] = data[j];
				data[j + n] = temp;
			}
		} 
	}while(n > 1);
}
void BubbleSort (int data[]) {
	// ð�������㷨
	// ʱ�临�Ӷȣ�O(n^2)
	int i, j, temp;
	bool flag = true;
	for (i = 0; i < MAX && flag; i++) {
		flag = false;
		for (j = MAX - 1; j >= i; j--) {
			if (data[j] > data[j + 1]) {
				temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
				flag = true; 
			}
		}	
	} 
}
void SelectSort (int data[]) {
	// ��ѡ������
	for (int i = 0; i <= MAX; i++) {
		for (int j = i + 1; j <= MAX; j++) {
			if (data[i] > data[j]) {
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	} 
} 
// ���������㷨 
int Partition (int data[], int low, int high) {
	int pivotkey = data[low];
	while(low < high){
		while(low < high && data[high] >= pivotkey) high--;
		data[low] = data[high]; 
		while(low < high && data[low] <= pivotkey) low++;
		data[high] = data[low];
	}
	data[low] = pivotkey;
	return low;
}
void QuickSort (int data[], int low, int high) {
	int pivot;
	if (low < high) {
		pivot = Partition(data, low, high);
		QuickSort(data, low, pivot - 1);
		QuickSort(data, pivot + 1, high);
	} 
} 


int main () {
	int data[MAX + 1] = {4,5,2,7,9,2,1,6}; 
	
	printf("��ǰ��\n"); 
	for (int i = 0; i <= MAX; i++)
		printf("%d", data[i]); 
	//InsertSort(data); ֱ�������㷨 
	//SellSort(data); ϣ�������㷨
	//BubbleSort(data); ð�������㷨
	//QuickSort(data, 0, MAX); ���������㷨
	SelectSort(data); 
	printf("\n�º�\n"); 
	for (int i = 0; i <= MAX; i++)
		printf("%d", data[i]); 
	
	return 0;
}
