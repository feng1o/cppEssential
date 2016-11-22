#include "iostream"
using namespace std;

class CM_member{
public:
	CM_member(){
		cout << "cm_member constructor!\n";
	}
	~CM_member(){
		cout << "cm_member destructor!\n";
	}
};

class Base{
public:
	Base():m_ib(0){
		cout << "base constructor!\n";
	}

	Base(const Base& origb):m_ib(origb.m_ib){
		cout << "base copy constructor!" << "   m_ib=" << m_ib << endl;;
	}

	~Base(){
		cout << "destructor base ~\n";
	}
private:
	int m_ib;
};

class CDrive :public Base{
public:
	CDrive() : m_inum(1){
		cout << "constucrtor cdrive \n";
	}

	//CDrive(const CDrive& origd):Base(origd){
	//	cout << "\ncdrive copy constructor!\n";
	//}
	CDrive(const Base& origd) :Base(origd){
		cout << "\ncdrive copy constructor!\n";
	}
	/*CDrive(const CDrive& origd) { //这个会调用基类的默认构造函数，不是拷贝 无:Base(origd)
		cout << "\ncdrive copy constructor!\n";
	}*/
	~CDrive(){
		cout << "destructor cdrive \n";
	}
private:
	//CM_member m_member;
	int m_inum;
};

int main(){
	CDrive cd;
	CDrive cd2 = cd;
	return 0;
}