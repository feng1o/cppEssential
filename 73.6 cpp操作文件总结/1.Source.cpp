#if 0
#include <iostream>  
#include <fstream>  
using namespace std;
void testByChar()
{
	fstream testByCharFile;
	char c;
	testByCharFile.open("inFile.txt", ios::in);
	while (!testByCharFile.eof())
	{
		testByCharFile >> c;
		cout << c;
	}
	testByCharFile.close();
}
void testByLine()
{
	char buffer[256];
	fstream outFile;
	outFile.open("inFile.txt", ios::in);
	cout << "inFile.txt" << "--- all file is as follows:---" << endl;
	while (!outFile.eof())
	{
		outFile.getline(buffer, 256, '\n');//getline(char *,int,char) ��ʾ�����ַ��ﵽ256�����������оͽ���  
		cout << buffer << endl;
	}
	outFile.close();
}
int main()
{
	cout << endl << "����ַ��Ķ�ȡ�ļ���testByChar() " << endl << endl;
	testByChar();
	cout << endl << "���ļ�ÿ�����ݴ洢���ַ����У�������ַ��� ��testByLine()" << endl << endl;
	testByLine();
}
#endif