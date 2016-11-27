
#if 01
/*
*
* 	Fax: (201) 236-3290
*/

#include "iostream"
#include "string"
using namespace std;

class Base
{
public:
	Base() :b(100)
	{
		//m_cStr = "xx";//const成员不能赋值，列表初始化，或者默认初始化
		cout << "constrator \n";
	}
	
	void fun(Base &cb)
	{
		cout << endl;
		cout << "no static fun ! \n";
		cout << "可访问非static成员b=" << b << endl;
		cout << "可访问static成员变量a=" << cb.a << endl;
	}
	static int  sfun(Base &cb) //静态成员函数不可声明为const,静态成员函数不能使用this指针
	{
		cout << endl;
		cout << "static sfun  \n";
		cout << "可访问static成员变量a=" << a << endl;
		//cout << "不可访问非static成员变量b=" <<Base:: b ； //只有通过传递对象，然后通过对象xx；xx.b肯定是可以的 静态成员函数不能使用this指针
		cout << "只能通过对象访问非static成员变量cb.b=" << cb.b << endl;
		return true;
	}

	const int cFun(string m_cStr,const Base cbas) const {  //这个地方的传递并不是传递给了类里面的成员,m_str非彼
		cout << endl;
		cout << "const函数调用const成员变量cstr=" << m_cStr << endl;
		cout << "const函数输出const成员变量cstr="<<cbas.m_cStr << endl;
		cout << "const函数输出非const成员变量cstr=" << cbas.b << endl;
		//cbas.b = 2;            //const成员函数不能修改非mutable的普通成员函数
		//return 1; //这样返回是ok的，但是如果是指针引用就不行，返回是ok，但是，1是一个局部变量，除了这个语句块就失效了
		int i = 2;
		//return i;
		return cbas.b; 
	}
	~Base() = default;

private:
	//static int  a=1;//不再是一个声明，而是定义，当函数fun执行到"t.a = 3;"时，不会再把a当成为一个外部符号，不会把它放入未解决符号表中。a首先被赋值为0
	static int a; //只是一个声明
	int b = 2;
	const string m_cStr = "const string";
};




int Base::a = 1; //使用前定义，就是一个外部符号来找到这里定义了再使用，，
void main()
{

	Base ba; //基类构造
	ba.fun(ba);
	ba.sfun(ba);
	Base bb;
	bb = ba;
	
	const Base cba; //const对象里面不能调用对象里面非const成员
	//cba.fun(cba); //const对象里面不能调用对象里面非const成员
	//cba.sfun(cba); //const对象里面不能调用对象里面非const成员
const	int ra = cba.cFun("adfb",cba);
	cout << endl << ra << endl;

	


#if 0
	auto a = 12.0F;
	std::cout << sizeof(a) << std::endl;
	int i = 20;
	decltype(i) bi1;
	decltype((i)) bi2 = bi1; //是引用 不是类型int了
#endif

#if 0
	std::cout << std::endl;
	int i = 0;
	int a = i++; //a=0;
	cout << a << endl;
	int b = ++a;//b=1  a=1???  此处类似b=(a=a+1);
	cout << "x" << a << b << endl;
	int  c = a + b; //c =2;
	cout << "x2:" << a << b << c << endl;//1 1 2
	int d;
	d = (a ? b : c); cout << "d: " << d << endl; //结果是1，不是其他
#endif

}
#endif
