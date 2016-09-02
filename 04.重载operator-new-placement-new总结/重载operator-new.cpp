#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

#include <iostream>
#include "string"

using namespace std;

class cPerson {
public:
	cPerson(int i=0) : i(i) {
		cout << "cPerson constructor." << endl;
	}
	
	~cPerson() NOEXCEPT {
		cout << "cPerson destructor." << endl;
	}

	void* operator new(size_t size){//这个是简单的一个非placement new，，，后面全部是placement new
		cout << "简单的非placement new ....\n";
		return malloc(sizeof(cPerson));
	}


	// 此处声明为static或non-static均可，下同
	/* static */ void *operator new(size_t size, void *p, const string& str){
		cout << "In our own operator new." << str << endl;
		cout << str << endl;
		if (!p) {
			cout << "Hey man, are you aware what you are doing?" << endl;
			return ::operator new(size); 
		}
		return p;
	}

	static void *operator new(size_t size, void *buf){
		cout << "\n调用2参数的placement new...\n";
		if (!buf)
		{
			cout << "new ..........\n";
			return  ::operator new(size);
		}
		else
			return buf;
	}	
	/* static */ void operator delete(void *p) {
		cout << "We should do nothing in operator delete." << endl;
		// 如果取消下一行的注释，程序会在执行时crash
		// ::operator delete(p);
	}

	void operator delete(void *buf, size_t size){
		while (size != 0 && --size)
		{
			::delete buf;
			//buf += sizeof(cPerson);
		}
	}


	void * operator new[](size_t size, void* buf){
		cout << "\noperator  new[]............\n";
		if (!buf)
		{
			return malloc(size*sizeof(cPerson));
		}
		else
			return buf;
	}
		void operator delete[](void* buf){
		return ::delete buf;
	}

	void getValue() {
		cout << "hello object, i: " << i << endl;
	}

private:
	int i;
};

int main() {
	cPerson *pc0 = new cPerson(10);
	pc0->getValue();
	//应该delete
	delete pc0;
	cout << "\n";

	char buf[sizeof(cPerson)];
	/*cPerson是第一个操作符（作为了成员函数），1024是调用构造的时候的初始值，第一个参数size_t已经自动去sizeof(cPerson)了，buf才是第二个，，*/
	cPerson *pc = new (buf, "Yeah, I'm crazy!") cPerson(1024);  //在栈上调用了 placement new
	pc->getValue();

	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
	cPerson* pc2 = new(0, "xxxx") cPerson; //在堆上分配的
	pc2->getValue();

	// 此处原本不应该调用delete，而应该只显式调用析构函数，但因为我们重载的operator delete并不做什么操作，所以是安全的
	//delete pc;
	//delete pc2;
	//yi应该调用
	pc->~cPerson();
	pc2->~cPerson();

	void *buf2 = static_cast<void*>(::operator new(sizeof(int)));
	cout << "buf2 ::&" << buf2 << endl;
	cPerson* pc3 = new (buf2)cPerson(10000);
	pc3->getValue();
	pc3->~cPerson();


	void *pc4 = operator new(sizeof(cPerson), buf2);
	//static_cast<cPerson> (cPerson(1000));
	cPerson *pc5 = new(pc4)cPerson(10000);
	pc5->getValue();
	//delete pc5;  //不要调用 delte,实际上，我们并没有在placement new上分配内存，，，只是使用了已经存在的内存空间，构造而已
	pc5->~cPerson();  //调用其析构

	//void * buf2 = malloc(4*sizeof(cPerson)); //ha好像不行？？？why，，，，
	cPerson *a_person1 = new (0) cPerson[3];  //
	a_person1[0].getValue();
	a_person1[1].getValue();
	return 0;
}