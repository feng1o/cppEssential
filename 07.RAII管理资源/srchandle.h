#ifndef _RESHANDLE_H_
#define _RESHANDLE_H_

#include "src.h"

using namespace std;

class cResHandle{
public:
	//cResHandle() :m_src(nullptr){};
	cResHandle(cSource* src) :m_src(new cSource(*src)){
		cout << "constructor...in..srchandler...\n";
	};
	cResHandle(const cSource* src) :m_src(new cSource(static_cast<const string>(*src->getPstr()))){
		cout << "const..constructor...in..src...\n";
	}; //cSource的构造函数必须是const的
	/*cResHandle(const cSource& src) :m_src(new cSource(static_cast<const string>(*src.m_str))){
		cout << "constructor...in..src...\n\n";
	};*/


	~cResHandle(){
		delete m_src; //这个不会抛出异常，是因为默认delete不会抛出，所以不需要再处理了
		cout << "destructor.....in...sourceHndle...\n";

	}
private:
	cResHandle(const cResHandle& srch){};  //EFC67 分析为什么RAII 一般都是不定义拷贝 移动操作 比如mutex的时候
	cResHandle& operator= (const cResHandle& srch){};

	cResHandle(cResHandle&& msrch){};
	cResHandle& operator=(cResHandle&&){};
	cSource * m_src; //看efc++ 70页，，一般这里使用的是智能指针，
};
#endif