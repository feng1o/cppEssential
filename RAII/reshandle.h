#ifndef _RESHANDLE_H_
#define _RESHANDLE_H_

#include "resources.h"

using namespace std;

class cResHandle{
public:
	//cResHandle() :m_src(nullptr){};
	cResHandle(const cSource& src) :m_src(new cSource(src)){
		cout << "constructor...in..src...\n\n";
	};
	cResHandle(const cSource& src) :m_src(new cSource(src.m_str)){
		cout << "constructor...in..src...\n\n";
	}; //cSource的构造函数必须是const的

	~cResHandle(){
		delete m_src; //这个不会抛出异常，是因为默认delete不会抛出，所以不需要再处理了
		cout << "destructor.....in...sourceHndle...\n\n";
		
	}
private:
	cSource * m_src;
};
#endif