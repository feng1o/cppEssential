#if 0
#include "iostream"
#include "new"
#include "string"
using namespace std;

class cPerson{
public:
	cPerson(string name, int age, int high) :m_name(new string(name)), m_iage(new int(age)), m_height(high){};
	//����Ĺ�����ܻᷢ����Դй¶���⣬������������ô�����
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