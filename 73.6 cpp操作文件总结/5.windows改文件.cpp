/*ʵ���滻�ļ���ָ��������
----Created by cryking----
ȫ����ȡ���ڴ棬Ȼ��д��ȥ
--------2012.02.12--------*/
#if 0
#include<iostream>  
#include<fstream>  
#include<string.h>  
#include<stdlib.h>  
using namespace std;

char *strstr_rep(char *source, char *old, char *ne)//�ַ��滻  
{
	char *org = source;
	char temp[256];
	int old_length = strlen(old);//��ý����滻���ַ����Ĵ�С  
	int i, j, k, location = -1;
	for (i = 0; source[i] && (location == -1); ++i)//location���ҽ����滻���ַ�����λ��  
		for (j = i, k = 0; source[j] == old[k]; j++, k++)
			if (!old[k + 1])
				location = i;
	if (location != -1)//��ʼ�滻  
	{
		for (j = 0; j<location; j++)//�Ȱѱ��滻���ַ�����ǰһ����COPY��temp  
			temp[j] = source[j];
		for (i = 0; ne[i]; i++, j++)//�ٰ��滻�����ַ���COPY��temp  
			temp[j] = ne[i];
		for (k = location + old_length; source[k]; k++, j++)//��ʣ�µ�����COPY��temp  
			temp[j] = source[k];
		temp[j] = NULL;
		for (i = 0; source[i] = temp[i]; i++); //����ʱ�ַ���temp���Ƹ�source  
	}
	return org;
}
int main()
{
	fstream outfile("test.txt", ios::out | ios::in);
	char ch;
	char buffer[255];
	int i = 0, k = 0;
	if (!outfile){
		cout << "���ܴ�Ŀ���ļ���test.txt" << '\n';
		exit(1);
	}

	outfile.unsetf(ios::skipws);//�ո�Ҳ��ȡ��buffer����
	while (outfile >> ch) {//���ļ�ȫ�����ݶ�����buffer  
		buffer[i] = ch;
		cout << ch;
		i++;
	}
	strstr_rep(buffer, "2222", "8888");//��"2000"�滻Ϊ8888"  
	outfile.close();
	ofstream infile("test.txt");
	while (k != i){ infile << buffer[k]; k++; }//��bufferȫ��д�뵽�ļ�  
	outfile.close();
	return 0;
}
#endif