#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

int main(){

	//setiosflags(ios::skipws) ����ǰ���հ�, ���¿����������������֪����~~
	//setiosflags(ios::skipws);
	string str, str2;
	cin.unsetf(ios::skipws);
	char ch;
	cin >> ch;  //cinĬ����set��skipws������ˣ����������һ���ո�Ȼ�������ַ�����ch���Ƕ�ȡ��һ����ĸ�������unsetf������ch���ȡ�Ǹ��ո�Ȼ���ַ���ֱ�ӱ�����Ķ�ȡ
	//cin >> str;
	cin >> str2;
	cout << ch << endl;
	cout << "jieguo:"<<str  << " 2:" << str2<< endl;
	string str3 = "  xxxxx3";
	cout << skipws << str3 << " hello,my boy~�����˿ո�setiosflags(ios::skipws)\n";


	istringstream istr(" 123 - 123");
	int a;
	istr >> noskipws >> a; //����ط�δskipws�����Զ�ȡ��һ�� �ո񣬵�intʧ�ܡ� cinĬ����ws��
	//istr >> ws;
	if (!istr){
		cerr << "��ȡ����\n";
		istr.clear();
	}
	istr >> skipws >> a; //cinĬ������skipws��
	cout << "a = " << a << "\n";
	char c;
	if (istr.get(c), c != '-'){ // ��_-_123����ȡ�˿ո�
		cerr << "����-\n";
		istr.unget();
	}
	if ((istr >> ws).get(c), c == '-'){ //skip�ո��ˣ�Ȼ���ڶ�ȡ��- ��ʣ�µ�_123,���Կո��ȡ123
		istr >> a;
		cout << "a = " << a << "\n";
	}
	/*
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
	*/
	return 0;
}