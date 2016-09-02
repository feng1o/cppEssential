#if 0
/*
* 1.左右值都必须立即初始化
* 2.tongchangyouzhi右值不鞥年绑定到左值
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