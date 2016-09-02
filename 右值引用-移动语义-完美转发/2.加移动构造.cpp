#if 0
#include "iostream"
#include "new"
#include "string"
using namespace std;

class cPerson{
public:
	cPerson(string name, int age, int high) :m_name(new string(name)), m_iage(new int(age)), m_height(high){
		cout << "construct cperson..." << ++m_cstnum << ".\n\n";
	};//这里的构造可能会发生资源泄露问题，，，，，，怎么解决？

	//cPerson(const cPerson& rhs) :m_name(new string(rhs.m_name)), m_iage(new int(rhs.m_iage)), m_height(rhs.m_height){};
	//const的拷贝构造函数，可以接受任何类型的参数，，移动构造失败的时候也是可以用他，，，
	cPerson(const cPerson& rhs) :m_name(new string(*rhs.m_name)), m_iage(new int(*rhs.m_iage)), m_height(rhs.m_height){
		cout << "copy construct ..." << ++m_cpcnum << "..\n\n";
	};

	cPerson(cPerson&& rhs) :m_name(rhs.m_name), m_iage(rhs.m_iage), m_height(rhs.m_height){
		rhs.m_name = nullptr;  //缺少这个两个在析构的时候会等价于  浅拷贝那种情况，出问题 悬挂指针
		rhs.m_iage = nullptr;
		cout << "move construct ..." << ++m_mvcnum << "..\n\n";
	};

	//cPerson(const cPerson&& rhs) :m_name(rhs.m_name), m_iage(rhs.m_iage), m_height(rhs.m_height){  //不能有const。。。。。
	//	rhs.m_name = nullptr;
	//	rhs.m_iage = nullptr;
	//	cout << "move construct ..." << ++m_mvcnum << "..\n\n";
	//};

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
	static  int  m_cstnum;
	static  int  m_delnum;
	static  int  m_cpcnum;
	static  int  m_mvcnum;
};

int cPerson::m_mvcnum = 0;
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