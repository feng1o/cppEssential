
#define  _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

int main(){
	//int n = 1;
	//char str[100];
	//scanf("%d", &n);
	//printf("n = %d\n", n);
	//gets(str);
	//puts(str);

	//Ok  ����c++�����getlineһ����ǰ�������룬���ȡ\n�س���Ϊ��
	int n = 1;
	char str[100];
	scanf("%d", &n);
	printf("n = %d\n", n);
	fflush(stdin);
	gets(str);
	puts(str);
	return 0;
}