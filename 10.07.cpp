#include <stdio.h>
#include <stdlib.h>
#define N 10
struct student {
	char num[4];
	char name[10];
	int score[3];
	float ave;
}stu[N], stud[N];

void StuSort (student *p) {
	student tmp; 
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (p[i].ave < p[j].ave) {
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			} 
		}
	}
}

int main () {
	int i = 0, j;
	FILE * fp;
	/*
	fp = fopen("D:\\tmp\\stud.txt", "wb");
	if (fp == NULL) {
		printf("写入文件失败，程序终止\n");
		exit(0);
	} 
	StuSort(stu);
	for (i = 0; i < N; i++) {
		fwrite(&stu[i], sizeof(student), 1, fp);
	} 
	fclose(fp);
	*/
	fp = fopen("D:\\tmp\\stud.txt", "rb");
	if (fp == NULL) {
		printf("读取文件失败，程序终止\n");
		exit(0);
	}
	for (i = 0; i < N; i++) {
		if (fread(&stud[i], sizeof(student), 1, fp) == 1) {
			printf("%s %s %d %d %d %6.2f\n", stud[i].num, stud[i].name, stud[i].score[0], stud[i].score[1], stud[i].score[2], stud[i].ave);
		} else {
			j = i;
			i = N;
		} 
	}
	fclose(fp); 
	printf("请输入新增学生学号 姓名 三科成绩："); 
	scanf("%s %s %d %d %d", stud[j].num, stud[j].name, &stud[j].score[0], &stud[j].score[1], &stud[j].score[2]); 
	stud[j].ave = (stud[j].score[0] + stud[j].score[1] + stud[j].score[2]) / 3.0;
	fp = fopen("D:\\tmp\\stu_sort2.txt", "wb");
	StuSort(stud);
	for (i = 0; i < N; i++) {
		if (stud[i].ave) {
			fwrite(&stud[i], sizeof(student), 1, fp);
		}
	} 
	fclose(fp);
	fp = fopen("D:\\tmp\\stu_sort2.txt", "rb");
	if (fp == NULL) {
		printf("读取文件失败，程序终止\n");
		exit(0);
	}
	for (i = 0; i < N; i++) {
		if (fread(&stu[i], sizeof(student), 1, fp) == 1) {
			printf("%s %s %d %d %d %6.2f\n", stu[i].num, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].ave);
		}
	}
	fclose(fp); 
	return 0;
} 
