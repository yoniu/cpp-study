// �Ӽ��������� 20 ���������ҳ�������Сֵ�������
 
#include <stdio.h>

int main () {
	int x[20], *p, temp = NULL;
	for (p = x; p < (x + 20); p++) 
		scanf("%d", p);
	for (p = &x[0]; p < (x + 20); p++) 
	{
		if (temp == NULL || *p < temp)
			temp = *p;
	}
	printf("\n%d\n", temp); 
	return 0;
}
