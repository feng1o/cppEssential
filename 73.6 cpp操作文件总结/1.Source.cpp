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
		outFile.getline(buffer, 256, '\n');//getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束  
		cout << buffer << endl;
	}
	outFile.close();
}
int main()
{
	cout << endl << "逐个字符的读取文件：testByChar() " << endl << endl;
	testByChar();
	cout << endl << "将文件每行内容存储到字符串中，再输出字符串 ：testByLine()" << endl << endl;
	testByLine();
}
#endif