#if 0
#include "iostream"
#include "new"
#include "memory"
#include "string"
using namespace std;

class cPerson{
public:
	//cPerson(string name, int age, int high) :m_name(new string(name)), m_iage(new int(age)), m_height(high){};
	//这里的构造可能会发生资源泄露问题，，e，，，，怎么解决？

	//智能指针不会出问题
	cPerson(string name, int age, int height) :m_shpName(new string(name)), m_shpage(new int(age)), m_height(height){};
	//cPerson(string name, int age, int high){
	//	m_height = high;
	//	m_iage = new int(age); //跑出异常没关系
	//	m_name = new string(name); //异常，会导致前面的 m_iage泄露
	//}
	~cPerson(){
		delete m_iage;
		delete m_name;
	}
	void printPersonInfo(){
		cout << "name" << m_name << "\t" << " age: " << m_iage << "\t" << "height:" << m_height << endl;
	}
private:
	shared_ptr<string> m_shpName;
	shared_ptr<int>    m_shpage;
	//string*  m_name;
	//int*     m_iage;
	int      m_height;
};




int main(){
	cPerson person_1("person_1", 20, 170);
	person_1.printPersonInfo();
	cPerson person_2(person_1);
	person_2.printPersonInfo();
}
#endif