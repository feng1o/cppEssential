/*
*explicit不仅能使用在构造函数里面，防止类型转换，
*也可用于让定义的转换成为一个显示类型的，必须显示
*/

#if 1


#include "iostream"
#include "string"

using namespace std;

class cAnimal{
public:
	cAnimal() = default;
	explicit cAnimal(string str) : _str(str){  //应该加explicit
		cout << "in canimal....\n\n";
	}
	cAnimal operator +(cAnimal rhs){
		cout << rhs._str << "......||||>>>>>" << _str;
		return cAnimal(rhs._str + _str);
	}
private:
	string _str;
};

class cPerson{
public:
	explicit cPerson(string str) :_str(str) {
		cout << "in person.....\n\n";
	}
	//operator cAnimal() const { return cAnimal(_str); };  //这个可以隐式转换，，
	//cAnimal tmp = anm_1 + person1;

	explicit operator cAnimal() const { return cAnimal(_str); };  //这个不可以。。。。
	//cAnimal tmp = anm_1 + static_cast<cAnimal>(person1);

private:
	string _str;
};

int main(){
	cPerson person1("person1----will change...");
	cAnimal anm_1("animal........");

	//cAnimal tmp = anm_1 + person1;
	cAnimal tmp = anm_1 + static_cast<cAnimal>(person1);
	return 0;
}
#endif