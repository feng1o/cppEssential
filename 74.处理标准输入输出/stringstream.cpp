#if 01
/*streamstring在调用str()时，会返回临时的string对象。而因为是临时的对象，所以它在整个表达式结束后将会被析构。

如果需要进一步操作string对象，先把其值赋给一个string变量后再操作。
Cpp代码  收藏代码

stringstream ss("012345678901234567890123456789012345678901234567890123456789");
//错误用法
const char* cstr2 = ss.str().c_str();
//正确用法
const string& str2 = ss.str();
const char* cstr2 = str2.c_str();


ss3.str("");  //清空他。。。。。。。。。。。。。。。。。。。。。。。。。。。。
使用stringstream时的清空操作

在C++中可以使用stringstream来很方便的进行类型转换，字符串串接，不过注意重复使用同一个stringstream对象时要 先继续清空，而清空很容易想到是clear方法，而在stringstream中这个方法实际上是清空stringstream的状态（比如出错等），
  ************************真 正清空内容需要使用.str("")方法。**************************
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


	ss3.clear();//如果你想通过使用同一stringstream对象实现多种类型的转换，请注意在每一次转换之后都必须调用clear()成员函数。 
	ss3.put('3');
	ss3.clear();  //只是清空状态，，，，，，，，，字符在里面
	ss3.str("");  //清空他。。。。。。。。。。。。。。。。。。。。。。。。。。。。
	ss3 << "ab";
	string stt;
	ss3 >> stt;
	cout << "stt=" << stt << endl;
	cout << "ss3.put(3)=" << ss3.str() << endl;  //不clear，，2还在里面，，所以必须clear..................



	return 0;
}
#endif