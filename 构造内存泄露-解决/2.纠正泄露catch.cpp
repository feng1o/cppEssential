#if 0
#include "iostream"
#include "new"
#include "string"
using namespace std;

class cPerson{
public:
	//cPerson(string name, int age, int high) :m_name(new string(name)), m_iage(new int(age)), m_height(high){};
	//����Ĺ�����ܻᷢ����Դй¶���⣬������������ô�����
	cPerson(string name, int age, int high){
		m_height = high;
		m_iage = new int(age); //�ܳ��쳣û��ϵ

		try{
			m_name = new string(name); //�쳣���ᵼ��ǰ��� m_iageй¶
		}
		catch (...){
			delete m_iage;
			throw;
		}
	}

	~cPerson(){
		try{
			delete m_iage;
			delete m_name;
		}
		catch (...) {}
	}
	void printPersonInfo(){
		cout << "name" << m_name << "\t" << " age: " << m_iage << "\t" << "height:" << m_height << endl;
	}
private:
	int*     m_iage;
	string*  m_name;
	int      m_height;
};




int main(){
	cPerson person_1("person_1", 20, 170);
	person_1.printPersonInfo();
	cPerson person_2(person_1);
	person_2.printPersonInfo();
}
#endif