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
	Base(){
		cout << "base constructor!\n";
	}
	~Base(){
		cout << "destructor base ~\n";
	}
};

class CDrive :public Base{
public:
	CDrive() {
		cout << "constucrtor cdrive \n";
	}
	~CDrive(){
		cout << "destructor cdrive \n";
	}
private:
	CM_member m_member;
};

int main(){
	CDrive cd;
	return 0;
}