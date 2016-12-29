
#define  _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

int main(){
	//int n = 1;
	//char str[100];
	//scanf("%d", &n);
	//printf("n = %d\n", n);
	//gets(str);
	//puts(str);

	//Ok  类似c++里面的getline一样，前面有输入，会读取\n回车，为空
	int n = 1;
	char str[100];
	scanf("%d", &n);
	printf("n = %d\n", n);
	fflush(stdin);
	gets(str);
	puts(str);
	return 0;
}