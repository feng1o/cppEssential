#if 01
/*�塢C++�ļ����ļ���λ
��C���ļ�������ʽ��ͬ���ǣ�C++ I/Oϵͳ����������һ���ļ�����ϵ��ָ�롣һ���Ƕ�ָ�룬��˵������������ļ��е�λ�ã���һ����дָ�룬���´�д������λ�á�ÿ��ִ����������ʱ����Ӧ��ָ���Զ��仯�����ԣ�C++���ļ���λ��Ϊ��λ�ú�дλ�õĶ�λ����Ӧ�ĳ�Ա������ seekg()�� seekp()��seekg()�����ö�λ�ã�seekp������дλ�á�������ͨ�õ���ʽ���£�
1.  istream &seekg(streamoff offset,seek_dir origin);
2.  ostream &seekp(streamoff offset,seek_dir origin);
streamoff������ iostream.h �У�������ƫ���� offset ����ȡ�õ����ֵ��seek_dir ��ʾ�ƶ��Ļ�׼λ�ã���һ��������ֵ��ö�٣�
ios::beg�� �ļ���ͷ
ios::cur�� �ļ���ǰλ��
ios::end�� �ļ���β
����������һ�����ڶ������ļ�����Ϊ�ı��ļ�����Ϊϵͳ���ַ��Ľ��Ͷ�������Ԥ���ֵ��ͬ��
����
1.  file1.seekg(1234,ios::cur);//���ļ��Ķ�ָ��ӵ�ǰλ�������1234���ֽ�
2.  file2.seekp(1234,ios::beg);//���ļ���дָ����ļ���ͷ�����1234���ֽ�
���vc��̵Ļ����ʹ��CFile��ȸ��ӷ������ļ�����.
tip:fseek����,seekp/g�����е� unsigned int������ɸ�����������תΪint��Ȼ���-��������Ϊһ���ܴ����

//
tip ��
	1.seekp/g���ļ�����ö����Ʒ�ʽ��������Сһ��
	2.fseek����,seekp/g�����е� unsigned int������ɸ�����������תΪint��Ȼ���-��������Ϊһ���ܴ����
	3.c++�����seekp()֮��fs.write()��֮�󣬻�Ҫ����fs.seekp()���������򣬲�����Ϊwrite�Զ��ƶ�ָ��λ��....��c��ͬ
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

		fs.seekg(-(int)sizeof(t), ios::cur); //����ת��Ϊint��Ȼ���-�ţ����򣬴���ĺ���Ƥ
			cout << fs.tellp() << " g:" << fs.tellg() << endl;

		fs.write((char*)&t, sizeof(t));

			cout << fs.tellp() << " g:" << fs.tellg() << endl;
			//fs.seekg(fs.tellg() + sizeof(t));
		fs.seekg((int)sizeof(t), ios::cur); //����ת��Ϊint��Ȼ���-�ţ����򣬴���ĺ���Ƥ

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
//r+���ж�д���ԣ����ļ�ͷ��ʼд������ԭ�ļ���û�б����ǵ����ݣ�\
w+���ж�д���ԣ�д��ʱ������ļ����ڣ��ᱻ��գ���ͷ��ʼд��
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