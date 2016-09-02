#if 0
#include "iostream"
#include "new"
#include "string"
using namespace std;

class cPerson{
public:
	cPerson(string name, int age, int high) :m_name(new string(name)), m_iage(new int(age)), m_height(high){
		cout << "construct cperson..."<< ++m_cstnum << ".\n\n";
	};
	//这里的构造可能会发生资源泄露问题，，，，，，怎么解决？
	//cPerson(const cPerson& rhs) :m_name(new string(rhs.m_name)), m_iage(new int(rhs.m_iage)), m_height(rhs.m_height){};
	cPerson(const cPerson& rhs) :m_name(new string(*rhs.m_name)), m_iage(new int(*rhs.m_iage)), m_height(rhs.m_height){
		cout << "copy construct ..." << ++m_cpcnum << "..\n\n" ;
	};
	~cPerson(){
		cout << "destruct ...." << ++m_delnum << "..\n\n";
		delete m_iage;
		delete m_name;
	}
	void printPersonInfo(){
		cout << "name" << *m_name << "\t" << " age: " << *m_iage << "\t" << "height:" << m_height << endl;
	}
private:
	string*  m_name;
	int*     m_iage;
	int      m_height;
const	static  int  m_icsnum = 0;
	static  int  m_cstnum ;
	static  int  m_delnum;
	static  int  m_cpcnum;
};


int cPerson::m_cstnum = 0;
int cPerson::m_cpcnum = 0;
int cPerson::m_delnum = 0;

cPerson getPerson(){
	cPerson tmpPerson("tmpPerson", 100, 100);
	tmpPerson.printPersonInfo();
	return tmpPerson;
}

int main(){
	//cPerson person_1("person_1", 20, 170);
	//person_1.printPersonInfo();
	//cPerson person_2(person_1);
	//person_2.printPersonInfo();
	cPerson  person = getPerson();  //vs优化了，，否则会2次拷贝构造，，实际这里做了1次
	return 0;
}
#endif