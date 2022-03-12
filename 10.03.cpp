#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
	
	FILE * fp;
	fp = fopen("E:\\test.txt", "wb"); 
	if (fp == NULL) {
		printf("读写文件失败，程序退出\n");
		exit(0); 
	} 
	printf("请输入字符串，以半角感叹号结束：");
	char ch = getchar();
	while(ch != '!'){
		ch = toupper(ch);
		fputc(ch, fp); 
		ch = getchar();
	}
	fclose(fp);
	fp = fopen("E:\\test.txt", "rb"); 
	if (fp == NULL) {
		printf("读写文件失败，程序退出\n");
		exit(0); 
	} 
	char ch2[100];
	fgets(ch2, 100, fp);
	if (ch2 == NULL) {
		printf("读取文件失败，程序退出\n");
		exit(0);
	} 
	printf("%s\n", ch2);
	fclose(fp); 
	return 0;
}
