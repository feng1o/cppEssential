#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

int main(){

	//setiosflags(ios::skipws) 忽略前导空白, 如下可以试下输入结果你就知道了~~
	//setiosflags(ios::skipws);
	string str, str2;
	cin.unsetf(ios::skipws);
	char ch;
	cin >> ch;  //cin默认是set了skipws，，因此，如果输入了一个空格，然后输入字符串，ch还是读取第一个字母，如果是unsetf（）后，ch会读取那个空格，然后字符串直接被后面的读取
	//cin >> str;
	cin >> str2;
	cout << ch << endl;
	cout << "jieguo:"<<str  << " 2:" << str2<< endl;
	string str3 = "  xxxxx3";
	cout << skipws << str3 << " hello,my boy~忽略了空格setiosflags(ios::skipws)\n";


	istringstream istr(" 123 - 123");
	int a;
	istr >> noskipws >> a; //这个地方未skipws，所以读取了一个 空格，到int失败。 cin默认是ws的
	//istr >> ws;
	if (!istr){
		cerr << "读取错误\n";
		istr.clear();
	}
	istr >> skipws >> a; //cin默认是有skipws的
	cout << "a = " << a << "\n";
	char c;
	if (istr.get(c), c != '-'){ // “_-_123”读取了空格
		cerr << "不是-\n";
		istr.unget();
	}
	if ((istr >> ws).get(c), c == '-'){ //skip空格了，然后在读取了- ，剩下的_123,忽略空格读取123
		istr >> a;
		cout << "a = " << a << "\n";
	}
	/*
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
	*/
	return 0;
}