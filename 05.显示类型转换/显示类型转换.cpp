/*
*explicit������ʹ���ڹ��캯�����棬��ֹ����ת����
*Ҳ�������ö����ת����Ϊһ����ʾ���͵ģ�������ʾ
*/

#if 1


#include "iostream"
#include "string"

using namespace std;

class cAnimal{
public:
	cAnimal() = default;
	explicit cAnimal(string str) : _str(str){  //Ӧ�ü�explicit
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
	//operator cAnimal() const { return cAnimal(_str); };  //���������ʽת������
	//cAnimal tmp = anm_1 + person1;

	explicit operator cAnimal() const { return cAnimal(_str); };  //��������ԡ�������
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