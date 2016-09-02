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

	void* operator new(size_t size){//����Ǽ򵥵�һ����placement new����������ȫ����placement new
		cout << "�򵥵ķ�placement new ....\n";
		return malloc(sizeof(cPerson));
	}


	// �˴�����Ϊstatic��non-static���ɣ���ͬ
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
		cout << "\n����2������placement new...\n";
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
		// ���ȡ����һ�е�ע�ͣ��������ִ��ʱcrash
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
	//Ӧ��delete
	delete pc0;
	cout << "\n";

	char buf[sizeof(cPerson)];
	/*cPerson�ǵ�һ������������Ϊ�˳�Ա��������1024�ǵ��ù����ʱ��ĳ�ʼֵ����һ������size_t�Ѿ��Զ�ȥsizeof(cPerson)�ˣ�buf���ǵڶ�������*/
	cPerson *pc = new (buf, "Yeah, I'm crazy!") cPerson(1024);  //��ջ�ϵ����� placement new
	pc->getValue();

	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
	cPerson* pc2 = new(0, "xxxx") cPerson; //�ڶ��Ϸ����
	pc2->getValue();

	// �˴�ԭ����Ӧ�õ���delete����Ӧ��ֻ��ʽ������������������Ϊ�������ص�operator delete������ʲô�����������ǰ�ȫ��
	//delete pc;
	//delete pc2;
	//yiӦ�õ���
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
	//delete pc5;  //��Ҫ���� delte,ʵ���ϣ����ǲ�û����placement new�Ϸ����ڴ棬����ֻ��ʹ�����Ѿ����ڵ��ڴ�ռ䣬�������
	pc5->~cPerson();  //����������

	//void * buf2 = malloc(4*sizeof(cPerson)); //ha�����У�����why��������
	cPerson *a_person1 = new (0) cPerson[3];  //
	a_person1[0].getValue();
	a_person1[1].getValue();
	return 0;
}