#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
�����ļ�����d��һ�����ֽ���sss.txt���ļ��У�����Ϊ��
1/5 2 3
-1 -3 4
1/2 3/5 6/4 -8

��Ҫ��txt�ļ��������ݲ��̶������з������ڣ�������Ҫ����δ���������ȶ�ȡ�ַ�����
Ȼ���ж��ַ��������Ƿ���'/',�������˵���Ƿ������ֱ��ҳ����Ӻͷ�ĸȻ��������ɡ�
*/

int main()
{
	int i = 0;
	float num[10];
	float temp[2];
	char d = '/';
	char *p, *q;

	char *str = (char*)malloc(10 * sizeof(char));
	FILE *fp;
	if (NULL == (fp = fopen("s.txt", "r")))
		return -1;

	while (EOF != (fscanf(fp, "%s", str)))
	{
		printf("%s \n", str);
		p = strtok(str, &d);//�ж��Ƿ����'/'�ַ�
		printf("strtok = %s\n\n", p);
		temp[0] = atof(str);//ȡ����
		printf("temp[0] = %f\n", temp[0]);
		if (NULL != (q = strtok(NULL, &d)))//ȡ��ĸ
		{
			temp[1] = atof(q);
			printf("temp[1]= %f\n", temp[1]);
			num[i] = temp[0] / temp[1];//���
		}
		else
			num[i] = temp[0];

		i++;
	}

	for (int j = 0; j<10; j++)
		printf("%f  ", num[j]);

	free(str);

	return 0;
}