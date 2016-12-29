#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
假设文件存在d盘一个名字叫做sss.txt的文件中，内容为：
1/5 2 3
-1 -3 4
1/2 3/5 6/4 -8

主要是txt文件数据内容不固定，和有分数存在，所以主要是如何处理分数：先读取字符串，
然后判断字符串里面是否有'/',如果有则说明是分数，分别找出分子和分母然后相除即可。
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
		p = strtok(str, &d);//判断是否存在'/'字符
		printf("strtok = %s\n\n", p);
		temp[0] = atof(str);//取分子
		printf("temp[0] = %f\n", temp[0]);
		if (NULL != (q = strtok(NULL, &d)))//取分母
		{
			temp[1] = atof(q);
			printf("temp[1]= %f\n", temp[1]);
			num[i] = temp[0] / temp[1];//相除
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