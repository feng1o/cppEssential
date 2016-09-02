#if 1
#include "iostream"
#include "new"
#include "string"
using namespace std;

class cPerson{
public:
	cPerson(string name, int age, int high) :m_name(new string(name)), m_iage(new int(age)), m_height(high){
		cout << "construct cperson....\n\n";
	};
	//这里的构造可能会发生资源泄露问题，，，，，，怎么解决？
	//cPerson(const cPerson& rhs) :m_name(new string(rhs.m_name)), m_iage(new int(rhs.m_iage)), m_height(rhs.m_height){};
	cPerson(const cPerson& rhs) :m_name(new string(*rhs.m_name)), m_iage(new int(*rhs.m_iage)), m_height(rhs.m_height){};
	~cPerson(){
		delete m_iage;
		delete m_name;
	}
	void printPersonInfo(){
		cout << "name" << m_name << "\t" << " age: " << m_iage << "\t" << "height:" << m_height << endl;
	}
private:
	string*  m_name;
	int*     m_iage;
	int      m_height;
};




int main(){
	cPerson person_1("person_1", 20, 170);
	person_1.printPersonInfo();
	cPerson person_2(person_1);
	person_2.printPersonInfo();
}
#endif