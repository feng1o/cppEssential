#include "iostream"
#include "string"

using namespace std;
class cB{
public:
	static int a;
	//int a;
};
class cBase{

};

class cDa : public virtual cBase{

};
class cDb : public virtual cBase{

};
class cDc : public cDa, public cDb{

};

int cB::a = 1;

int main(){
	cB base;
	cout << cB::a << endl;
	cout << "cbase = " << sizeof(cB) << endl;
	cout << "base = " << sizeof(cBase) << endl;
	cout << "da= " << sizeof(cDa) << endl;
	cout << "dc= " << sizeof(cDc) << endl;
}