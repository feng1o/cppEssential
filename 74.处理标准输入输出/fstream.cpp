#if 01

#include "fstream"
#include "iostream"
#include "cstdlib"
#include "cstdio"
#include "string"

using namespace std;

int main(){
	fstream  fs;
	//fs.open("data.txt",  ios::out | ios::in);  //���ַ�ʽ����Ĭ���Ѿ������ļ�����Ϊ�Ƕ����������ڵ��ļ���Ȼ���ᴴ��
	//��дһ���û�ļ������ᴴ����������out��д�ļ��������ھͻᴴ��һ���ļ�....tip
	//fs.open("data.txt");  //���ַ�ʽ����Ĭ���Ѿ������ļ�����Ϊ�Ƕ����������ڵ��ļ���Ȼ���ᴴ��
	fs.open("data.t",ios::out | ios::binary);  //���ַ�ʽ����Ĭ���Ѿ������ļ�����Ϊ�Ƕ����������ڵ��ļ���Ȼ���ᴴ��

	if (fs.is_open())
	{
		cout << "...l.ok..\n";
	}
	string str2 = "abcdefg";
	//fs << "abcdefg\n";
	fs << str2.c_str() <<endl;
	//string str;
	char *str = new char[100];
	fs.read(str, 2);
	cout << "read...." << str << endl;
	//fs >> str;
	//cout << "..." << str.c_str() << endl;
	fs.close();


	//ֻ���򿪣������뱣֤�ļ����ڣ����򲻻�򿪣�������������
	ifstream ifs("data.txt");
	if (ifs)  //ifs.io_open()�ȼ۵�...................
	{
		cout << "ok22222222222222222\n";
	}
	char c;
	ifs >> c;
	ifs >> str;
	cout << "c= " << c << endl;
	//cout << "str = " << str << endl;

	char str1[] = "I Love You";
	char n[5];
	ofstream out("yyy.yyy");
	out.write(str1, 10);//���ַ���str1ȫ��д��yyy.yyy��    
	out.close();

	ifstream in("yyy.yyy");
	if (in.is_open()){
		cout << "................in.....\n";
	}
	in.read(n, 5);//��xxx.xxx�ж�ȡָ����������ע������ת��   
	cout << "n=" << n << endl;
	in.close(); 

	return 0;
}
#endif