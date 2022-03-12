#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
	FILE * fp;
	int i, j, ii, n;
	char c[100], t, ch;
	fp = fopen ("D:\\tmp\\a.txt", "rb");
	if (fp == NULL) {
		printf("读取文件失败，程序退出\n");
		exit(0);
	} 
	for (i = 0; (ch = fgetc(fp)) != EOF; i++) {
		c[i] = ch;
		putchar(ch);
	}
	fclose(fp);
	ii = i;
	fp = fopen("D:\\tmp\\b.txt", "rb");
	if (fp == NULL) {
		printf("读取文件失败，程序退出\n");
		exit(0); 
	} 
	for (i = ii; (ch = fgetc(fp)) != EOF; i++) {
		c[i] = ch;
		putchar(ch);
	}
	fclose(fp);
	fp = fopen("D:\\tmp\\c.txt", "wb");
	if (fp == NULL) {
		printf("写入文件失败，程序退出\n");
		exit(0); 
	}
	n = i;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if(c[i] > c[j]) {
				t = c[i];
				c[i] = c[j];
				c[j] = t;
			}
		}
	} 
	c[i] = '\0';
	fprintf(fp, "%s", c);
	printf("\n%s\n", c);
	fclose(fp);
	return 0;
} 
