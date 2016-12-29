#if 1
#include "iostream"
#include "new"
#include "string"
using namespace std;

class cPerson{
public:
	//cPerson(string name, int age, int high) :m_name(new string(name)), m_iage(new int(age)), m_height(high){};
	cPerson(string naem, int age, int height) :m_name(new string(naem)), m_iage(initAge(age)), m_height(height){};

	cPerson(const cPerson& rhs) : m_name(new string(*rhs.m_name)), m_iage(initAge(*rhs.m_iage)), m_height(rhs.m_height){}; 
	~cPerson(){
		delete m_iage;
		delete m_name;
	}
	void printPersonInfo(){
		cout << "name" << m_name << "\t" << " age: " << m_iage << "\t" << "height:" << m_height << endl;
	}

private:
	int* initAge(int age){
		try
		{
			return new int(age);
		}
		catch (...)
		{
			delete m_name; //�ͷŵ�һ���������Դ��
			throw;
		}

	}
private:
	string*  m_name;
	int*  const  m_iage;  //��ʱ��const�ˣ�����ʹ�õ�2�֣��������б��ʼ��������ν�����ֲ���������ָ��Ļ�
	int      m_height;
};

int main(){
	cPerson person_1("person_1", 20, 170);
	person_1.printPersonInfo();
	cPerson person_2(person_1);
	person_2.printPersonInfo();

}
#endif