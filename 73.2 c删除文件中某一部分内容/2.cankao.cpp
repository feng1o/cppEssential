#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char *insert = "EE,EE,EE,", tmp[256] = { 0 };
	int pos, i;

	/*test.txt�ļ����ݣ�01,00,00,00,0E,00,00,00,00,00,00,E1,E2,00,00,00,00*/
	fp = fopen("test.txt", "rt+");

	/*1���ȳ�����*/
	fseek(fp, 12, 1);
	fprintf(fp, "0F");  /*ֱ��д��ȳ��ȵ����ݾͿ�����ɸ���*/
	
	/*2��E2����롰EE,EE,EE,�� */
	fseek(fp, 25, 1);
	pos = ftell(fp);  /*����λ��*/
	fgets(tmp, 256, fp);  /*�Ѻ�������ݻ���*/
	fseek(fp, pos, 0);   /*�ƶ�������λ��*/
	fprintf(fp, insert); /*���룬����д������*/
	fprintf(fp, tmp);    /*��ԭ����������д������ ���*/

	/*3��01��ȡ��++���Σ�������д���ļ�*/
	rewind(fp);
	fscanf(fp, "%x", &i);   /*��ȡ����*/
	i = i + 2;           /* +2 */
	fseek(fp, -2, 1);  /*����ָ��*/
	fprintf(fp, "%02x", i);  /*д�ļ�*/

	fclose(fp);
	system("PAUSE");
	return 0;
}