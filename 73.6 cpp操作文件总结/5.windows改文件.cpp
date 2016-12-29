/*实现替换文件中指定的内容
----Created by cryking----
全部读取到内存，然后写回去
--------2012.02.12--------*/
#if 0
#include<iostream>  
#include<fstream>  
#include<string.h>  
#include<stdlib.h>  
using namespace std;

char *strstr_rep(char *source, char *old, char *ne)//字符替换  
{
	char *org = source;
	char temp[256];
	int old_length = strlen(old);//获得将被替换的字符串的大小  
	int i, j, k, location = -1;
	for (i = 0; source[i] && (location == -1); ++i)//location查找将被替换的字符串的位置  
		for (j = i, k = 0; source[j] == old[k]; j++, k++)
			if (!old[k + 1])
				location = i;
	if (location != -1)//开始替换  
	{
		for (j = 0; j<location; j++)//先把被替换的字符串的前一部分COPY到temp  
			temp[j] = source[j];
		for (i = 0; ne[i]; i++, j++)//再把替换的新字符串COPY到temp  
			temp[j] = ne[i];
		for (k = location + old_length; source[k]; k++, j++)//把剩下的内容COPY到temp  
			temp[j] = source[k];
		temp[j] = NULL;
		for (i = 0; source[i] = temp[i]; i++); //把临时字符串temp复制给source  
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
		cout << "不能打开目的文件：test.txt" << '\n';
		exit(1);
	}

	outfile.unsetf(ios::skipws);//空格也读取到buffer里面
	while (outfile >> ch) {//将文件全部内容读出到buffer  
		buffer[i] = ch;
		cout << ch;
		i++;
	}
	strstr_rep(buffer, "2222", "8888");//将"2000"替换为8888"  
	outfile.close();
	ofstream infile("test.txt");
	while (k != i){ infile << buffer[k]; k++; }//将buffer全部写入到文件  
	outfile.close();
	return 0;
}
#endif