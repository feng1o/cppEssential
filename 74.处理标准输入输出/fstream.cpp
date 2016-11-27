#if 01

#include "fstream"
#include "iostream"
#include "cstdlib"
#include "cstdio"
#include "string"

using namespace std;

int main(){
	fstream  fs;
	//fs.open("data.txt",  ios::out | ios::in);  //这种方式必须默认已经存在文件，因为是读，，不存在的文件自然不会创建
	//读写一起打开没文件，不会创建，，单独out，写文件，不存在就会创建一个文件....tip
	//fs.open("data.txt");  //这种方式必须默认已经存在文件，因为是读，，不存在的文件自然不会创建
	fs.open("data.t",ios::out | ios::binary);  //这种方式必须默认已经存在文件，因为是读，，不存在的文件自然不会创建

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


	//只读打开，，必须保证文件存在，否则不会打开，，，，，，，
	ifstream ifs("data.txt");
	if (ifs)  //ifs.io_open()等价的...................
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
	out.write(str1, 10);//把字符串str1全部写到yyy.yyy中    
	out.close();

	ifstream in("yyy.yyy");
	if (in.is_open()){
		cout << "................in.....\n";
	}
	in.read(n, 5);//从xxx.xxx中读取指定个整数，注意类型转换   
	cout << "n=" << n << endl;
	in.close(); 

	return 0;
}
#endif