#if 0
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

int main()
{
	char* str = (char*) calloc(1,sizeof(char));  //����new��������
	scanf("%s", str);
	printf("sss = %s", str);

	char ch;
	scanf("%s", &ch);
	printf("sss = %c\n", ch);
	return 0;
}
#endif
#if 0

#include"stdlib.h"
#include"stdio.h"


int IsIncluded(int x, int array[3])//x�Ƿ������������ 
{
	if ((array[0] != x) && (array[1] != x) && (array[2] != x))
		return 0;
	return 1;
}
int Left(int k, int array[3], int V[8][3])//ʵ��V'-{k} ���±���� 
{
	int i = 0, index = 0, array_0_count = 0, array_1_count = 0, array_2_count = 0, array_3_count = 0;
	int V_0_count = 0, V_1_count = 0, V_2_count = 0, V_3_count = 0;
	int temp[3];
	for (i = 0; i < 3; i++)
		temp[i] = array[i];
	for (i = 0; i < 3; i++)
		if (temp[i] == k)
			temp[i] = 0;  //�൱��ȥ��k������� 
	for (i = 0; i < 3; i++)
	{
		if (temp[i] == 0)
			array_0_count++;
		else if (temp[i] == 1)
			array_1_count++;
		else if (temp[i] == 2)
			array_2_count++;
		else
			array_3_count++;
	}
	for (index = 0; index < 8; index++)
	{
		for (i = 0; i < 3; i++)
		{
			if (V[index][i] == 0)
				V_0_count++;
			else if (V[index][i] == 1)
				V_1_count++;
			else if (V[index][i] == 2)
				V_2_count++;
			else
				V_3_count++;
		}
		if ((array_0_count == V_0_count) && (array_1_count == V_1_count)
			&& (array_2_count == V_2_count) && (array_3_count == V_3_count))
			return index;
		V_0_count = 0;
		V_1_count = 0;
		V_2_count = 0;
		V_3_count = 0;
	}
	return 0;
}

void TSP(int d[4][8], int c[4][4], int V[8][3], int n)
{
	int i = 0, j = 0, k = 0;

	for (i = 1; i < n; i++)//V'Ϊ��ʱ������ֵ�� 
		d[i][0] = c[i][0];

	for (j = 1; j < 7; j++)//���б�����ͬ���ϣ�{1},{2},{3},{1,2},{1,3}..... 
	{
		for (i = 1; i < n; i++)//��������1��2��3 
		{
			if (!IsIncluded(i, V[j]))//i���벻�ڼ����У���������ھ������Σ����������� 
			{
				for (k = 0; k < 3; k++)//�ֱ���̽�����е�ÿһ�㣬ȡ��Сֵ 
				{
					if ((V[j][k] != 0) && ((c[i][V[j][k]] + d[V[j][k]][Left(V[j][k], V[j], V)]) < d[i][j]))
						d[i][j] = c[i][V[j][k]] + d[V[j][k]][Left(V[j][k], V[j], V)];
				}
			}
		}//end of     for(i = 1; i < n; i++)//��������1��2��3 
	}//end of for(j = 1; j < ((int)pow(2,n)-1); j++) 
	for (k = 0; k < 3; k++)//�ֱ���̽��һ��Ϊ�����е��κ�һ�㣬ȡ��Сֵ 
	{
		if ((V[7][k] != 0) && (c[0][V[7][k]] + d[V[7][k]][Left(V[7][k], V[7], V)]) < d[0][7])
			d[0][7] = c[0][V[7][k]] + d[V[7][k]][Left(V[7][k], V[7], V)];
	}
}
void main()
{
	int V[8][3] =
	{
		0, 0, 0,
		0, 0, 1,
		0, 0, 2,
		0, 0, 3,
		0, 1, 2,
		0, 1, 3,
		0, 2, 3,
		1, 2, 3
	};
	int c[4][4] =
	{
		0, 3, 6, 7,
		5, 0, 2, 3,
		6, 4, 0, 2,
		3, 7, 5, 0
	};
	int d[4][8] = { 0 }, i = 0, j = 0;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 8; j++)
			d[i][j] = 1000;   //����1000Ϊ����� 
	TSP(d, c, V, 4);
	printf("The least road is:%d/n", d[0][7]);
}
#endif