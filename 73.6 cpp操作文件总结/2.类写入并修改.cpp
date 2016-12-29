#if 01
/*五、C++文件流文件定位
和C的文件操作方式不同的是，C++ I/O系统管理两个与一个文件相联系的指针。一个是读指针，它说明输入操作在文件中的位置；另一个是写指针，它下次写操作的位置。每次执行输入或输出时，相应的指针自动变化。所以，C++的文件定位分为读位置和写位置的定位，对应的成员函数是 seekg()和 seekp()，seekg()是设置读位置，seekp是设置写位置。它们最通用的形式如下：
1.  istream &seekg(streamoff offset,seek_dir origin);
2.  ostream &seekp(streamoff offset,seek_dir origin);
streamoff定义于 iostream.h 中，定义有偏移量 offset 所能取得的最大值，seek_dir 表示移动的基准位置，是一个有以下值的枚举：
ios::beg： 文件开头
ios::cur： 文件当前位置
ios::end： 文件结尾
这两个函数一般用于二进制文件，因为文本文件会因为系统对字符的解释而可能与预想的值不同。
例：
1.  file1.seekg(1234,ios::cur);//把文件的读指针从当前位置向后移1234个字节
2.  file2.seekp(1234,ios::beg);//把文件的写指针从文件开头向后移1234个字节
如果vc编程的话最好使用CFile类等更加方便于文件操作.
tip:fseek（）,seekp/g（）中的 unsigned int如果想变成负数，必须先转为int，然后加-，否则会成为一个很大的数

//
tip ：
	1.seekp/g打开文件最好用二进制方式，这样大小一样
	2.fseek（）,seekp/g（）中的 unsigned int如果想变成负数，必须先转为int，然后加-，否则会成为一个很大的数
	3.c++里面的seekp()之后fs.write()了之后，还要调用fs.seekp()回来，否则，不会因为write自动移动指针位置....和c不同
*/
#include <iostream>  
#include <fstream>  
#include <string>
#include <sstream>
using namespace std;

class Test{
public:
	Test(int n, char *str) :m_n(n){ strcpy(m_chArr, str); };
	~Test(){};
	//void print(){
	//	cout << m_n << " " << m_chArr << endl;
	//}
	//string toSring(){
	//	stringstream ss;
	//	ss << m_n;
	//	//ss << "\n";
	//	ss << m_chArr;
	//	string str;
	//	ss >> str;
	//	return str;
	//}
//private:
	int		m_n;
	//string	m_str;
	char	m_chArr[100];
};
struct str{
	char a[100];
	int  n ;
};
int main(){
	struct str t;
	fflush(stdin);
	strcpy(t.a, "aa");
	t.n = 11;

	remove("data.txt"); 
	fstream fs;
	fs.open("data.txt", ios::out | std::ios::binary | std::fstream::trunc);
	//fs.open("data.txt", fstream::in + ios::out | std::ios::binary /*| std::fstream::trunc*/);
	if (fs.is_open())
		cout << "open \n"; 
	else 
		cout << " open error\n";
	cout << "tellg:" << fs.tellp() << endl;
	fs.write((char*)&t, sizeof(t));
	fs.sync();
	strcpy(t.a, "bb");
	cout << "tellg:" << fs.tellp() << endl;
	fs.write((char*)&t, sizeof(t));
	cout << "tellg:" << fs.tellp() << endl;

	strcpy(t.a, "cc");
	fs.write((char*)&t, sizeof(t));
	cout << "tellg:" << fs.tellg() << endl;

	strcpy(t.a, "xxxxxxxxxxxxxxxxxx");
	t.n = 9999;
	fs.write((char*)&t, sizeof(t));
	//fs.seekp(-sizeof(t), ios::cur);
	cout << "tellg:" << fs.tellg() << endl;
	fs.close();

	fs.open("data.txt", ios::in + ios::out | ios::binary);
	while (fs.read((char*)&t, sizeof(t))){
		cout << t.a << "  " << t.n << endl;
		if (strcmp(t.a, "bb") == 0){
			cout << endl;
			strcpy(t.a, "ooooooo");
			cout << fs.tellp() << " g:" << fs.tellg() << endl;

		fs.seekg(-(int)sizeof(t), ios::cur); //必须转换为int，然后家-号，否则，错误的很里皮
			cout << fs.tellp() << " g:" << fs.tellg() << endl;

		fs.write((char*)&t, sizeof(t));

			cout << fs.tellp() << " g:" << fs.tellg() << endl;
			//fs.seekg(fs.tellg() + sizeof(t));
		fs.seekg((int)sizeof(t), ios::cur); //必须转换为int，然后家-号，否则，错误的很里皮

			cout << fs.tellp() << " g:" << fs.tellg() << endl;
			cout << " write \n\n";
		}
	}
	fs.close();


	fs.open("data.txt", ios::in | ios::out);
	while (fs.read((char*)&t, sizeof(t))){
		cout << t.a << "  " << t.n << endl;
	}
	fs.close();
	return 0;




	Test tt(1, "xxxx");
	/*t.print();
	cout << t.toSring() << endl;
	cout << sizeof(t) << endl;
	*/
	fstream fs2;
	fs2.open("data.txt", ios::in | ios::out);
	if (fs2.is_open()){
		fs2.write((const char*)&t, sizeof(t));
		//fs.write(t.toSring().c_str(), t.toSring().length());

	}
	Test t2(0, "bb");
	char a[100];
	fs2.read((char*)&t2, sizeof(t2));
	cout << t2.m_chArr << endl;
	cout << t2.m_n << endl;
	//fs.read((char*)a, 6);
	//cout << a << endl;
	//t2.print();
	return 0;
}
#endif

/*c
int changeMoney(typeAccount acct){
FILE *fp = fopen("account.txt", "rb+");
//r+具有读写属性，从文件头开始写，保留原文件中没有被覆盖的内容；\
w+具有读写属性，写的时候如果文件存在，会被清空，从头开始写。
if (!fp)
{
	fprintf(stderr, "open file error! \n");
	exit(-1);   //open error
}
int i = 0;
typeAccount racct;
while (fread(&racct, sizeof(racct), 1, fp)){
	if (strcmp(racct.name, racct.name) == 0 && 0 == strcmp(racct.passWd, acct.passWd)) // find the account 
	{
		fseek(fp, -(int)sizeof(typeAccount), SEEK_CUR); //rewrite the accounts values;
		fwrite(&acct, sizeof(typeAccount), 1, fp);
		fclose(fp);
		return racct.money;
	}
	if (feof(fp)){
		break;
	}
}
fclose(fp);
return -1;
}*/