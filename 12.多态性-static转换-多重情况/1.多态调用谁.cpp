#include "iostream"
#include "vector"

using namespace std;
class Base{
public:
	virtual void print(){
		cout << "b" << endl;
	}
};
class A : public Base{
public:
	virtual void fun(){}
	virtual void print(){
		cout << "A" << endl;
	};
};

class B : public Base{
public:
	virtual void print(){
		cout << "B" << endl;
	};
};

class C : public A {
public:
	virtual void print(){
		cout << "C" << endl;
	};
};

class D : public A{
public:
	virtual void print(){
		cout << "D" << endl;
	};
};


int main(){
	vector<void*> vec;
	vec.push_back(new Base());
	vec.push_back(new A());
	vec.push_back(new B());
	vec.push_back(new C());
	vec.push_back(new D());
	for (auto it : vec)
	{
		static_cast<D*>(it)->print();
	}
	return 0;
}