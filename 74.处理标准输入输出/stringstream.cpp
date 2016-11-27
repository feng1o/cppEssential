#if 01
/*streamstring�ڵ���str()ʱ���᷵����ʱ��string���󡣶���Ϊ����ʱ�Ķ������������������ʽ�����󽫻ᱻ������

�����Ҫ��һ������string�����Ȱ���ֵ����һ��string�������ٲ�����
Cpp����  �ղش���

stringstream ss("012345678901234567890123456789012345678901234567890123456789");
//�����÷�
const char* cstr2 = ss.str().c_str();
//��ȷ�÷�
const string& str2 = ss.str();
const char* cstr2 = str2.c_str();


ss3.str("");  //�������������������������������������������������������������
ʹ��stringstreamʱ����ղ���

��C++�п���ʹ��stringstream���ܷ���Ľ�������ת�����ַ������ӣ�����ע���ظ�ʹ��ͬһ��stringstream����ʱҪ �ȼ�����գ�����պ������뵽��clear����������stringstream���������ʵ���������stringstream��״̬���������ȣ���
  ************************�� �����������Ҫʹ��.str("")������**************************
*/
#include "sstream"
#include "string"
#include "iostream"

using namespace std;

int main(){
	string str = "abc";
	stringstream ss(str);
	stringstream ss2;
	ss2 << str;
	ss2.put('p');
	string tmp;
	ss2 >> tmp;
	cout << "ss2=" << ss2.str() << "   tmp : " << tmp << endl;
	cout << ss.str() << endl;

	stringstream ss3;
	ss3 << 2;
	string str3 = ss3.str();
	cout << endl << "str3==" << str3 << endl;


	ss3.clear();//�������ͨ��ʹ��ͬһstringstream����ʵ�ֶ������͵�ת������ע����ÿһ��ת��֮�󶼱������clear()��Ա������ 
	ss3.put('3');
	ss3.clear();  //ֻ�����״̬�������������������ַ�������
	ss3.str("");  //�������������������������������������������������������������
	ss3 << "ab";
	string stt;
	ss3 >> stt;
	cout << "stt=" << stt << endl;
	cout << "ss3.put(3)=" << ss3.str() << endl;  //��clear����2�������棬�����Ա���clear..................



	return 0;
}
#endif