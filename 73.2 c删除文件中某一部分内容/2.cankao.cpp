#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char *insert = "EE,EE,EE,", tmp[256] = { 0 };
	int pos, i;

	/*test.txt文件内容：01,00,00,00,0E,00,00,00,00,00,00,E1,E2,00,00,00,00*/
	fp = fopen("test.txt", "rt+");

	/*1、等长覆盖*/
	fseek(fp, 12, 1);
	fprintf(fp, "0F");  /*直接写入等长度的数据就可以完成覆盖*/
	
	/*2、E2后插入“EE,EE,EE,” */
	fseek(fp, 25, 1);
	pos = ftell(fp);  /*插入位置*/
	fgets(tmp, 256, fp);  /*把后面的数据缓存*/
	fseek(fp, pos, 0);   /*移动到插入位置*/
	fprintf(fp, insert); /*插入，就是写入数据*/
	fprintf(fp, tmp);    /*把原来的数据再写回来， 完成*/

	/*3、01读取后++两次，并重新写回文件*/
	rewind(fp);
	fscanf(fp, "%x", &i);   /*读取数据*/
	i = i + 2;           /* +2 */
	fseek(fp, -2, 1);  /*调整指针*/
	fprintf(fp, "%02x", i);  /*写文件*/

	fclose(fp);
	system("PAUSE");
	return 0;
}