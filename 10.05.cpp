#include <stdio.h>
#include <stdlib.h>
struct student {
	char num[4];
	char name[10];
	int score[3];
	float ave;
}stu[5], stud[5];

int main () {
	int i = 0;
	for (i = 1; i <= 5; i++) {
		student * tmp = &stu[i - 1];
		printf("������ѧ�� %d ��ѧ�� ���� ���Ƴɼ���", i); 
		scanf("%s %s %d %d %d", tmp->num, tmp->name, &tmp->score[0], &tmp->score[1], &tmp->score[2]); 
		tmp->ave = (tmp->score[0] + tmp->score[1] + tmp->score[2]) / 3.0;
	}
	FILE * fp;
	fp = fopen("D:\\tmp\\stud.txt", "wb");
	if (fp == NULL) {
		printf("д���ļ�ʧ�ܣ�������ֹ\n");
		exit(0);
	} 
	for (i = 0; i < 5; i++) {
		fwrite(&stu[i], sizeof(student), 1, fp);
	} 
	fclose(fp); 
	fp = fopen("D:\\tmp\\stud.txt", "rb");
	if (fp == NULL) {
		printf("��ȡ�ļ�ʧ�ܣ�������ֹ\n");
		exit(0);
	}
	for (i = 0; i < 5; i++) {
		fread(&stud[i], sizeof(student), 1, fp);
		printf("%s %s %d %d %d %6.2f\n", stud[i].num, stud[i].name, stud[i].score[0], stud[i].score[1], stud[i].score[2], stud[i].ave);
	}
	fclose(fp); 
	return 0;
} 
