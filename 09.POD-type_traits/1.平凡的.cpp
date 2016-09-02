/*
	这并不是说Aggregate类型就不能有构造函数，事实上，它可以拥有一个默认构造函数或者一个复制构造函数，只要他们是被编译器声明的，而不是被用户自己声明的。
	不能拥有私有或者保护类型的非静态数据成员。你可以定义任意多的私有或者保护类型的成员方法（不包括构造函数）和静态类型的数据成员和方法，这都不违背Aggregate类型的规则。
	Aggregate类型可以拥有用户声明的/用户定义的 赋值操作符或者析构函数
	数组是Aggregate类型，即便是非Aggregate类型元素的数组。

	字节赋值，可使用memcpy，memset初始化，比如stl里面这样的就不会调用构造函数了，
	与c兼容，是安全的
	pod类型的静态初始化为0，在.bss段里面，不占空间，静态initialization
*/
#include "iostream"
#include "string"
#include "type_traits"
#include "iomanip"
using namespace std;

class NotAggregate1
{
	virtual void f(){} //remember? no virtual functions
};

class NotAggregate2
{
	int x; //x is private by default and non-static 
};

class NotAggregate3
{
public:
	NotAggregate3(int) {} //oops, user-defined constructor
};

class Aggregate1
{
public:
	NotAggregate1 member1;   //ok, public member
	Aggregate1& operator = (Aggregate1 const & rhs) {/* */ } //ok, copy-assignment  
private:
	void f() {} // ok, just a private function

};
struct cStr{
//	virtual ~cStr(){};
};
class Cperson{
public:
	Cperson() = default;
	virtual ~Cperson(){};
private:
	int i;
};

class cMan : public Cperson{
public:
	cMan() :Cperson(){

	}
	~cMan(){};
private:
	string name;
};



int main(){
	cout << std::boolalpha;
	cout << is_trivial<cStr>::value << endl;
	cout << is_trivial<Cperson>::value << endl;
	
	cout << "\n标准布局？\n";
	cout << is_standard_layout<Cperson>::value << endl;


	cout << "\n是不是pod？\n";
	cout << is_pod<Cperson>::value << endl;

	return 0;
}