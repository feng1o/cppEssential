#if 0
/*
* 1.����ֵ������������ʼ��
* 2.tongchangyouzhi��ֵ���E��󶨵���ֵ
*/


#if 1
#include "iostream"
#include "type_traits"
#include "iomanip"

using namespace std;

int main(){
	int i = 0;
	int &&rri = std::move(i);

	cout << "type_traits_isleftvalue:::stirng:::" << is_lvalue_reference<string>::value << endl;
	cout << "type_traits_isleftvalue:::stirng:::" << is_lvalue_reference<string& >::value << endl;
	return 0;
}
#endif
#endif