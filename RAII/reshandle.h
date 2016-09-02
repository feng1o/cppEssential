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
	}; //cSource�Ĺ��캯��������const��

	~cResHandle(){
		delete m_src; //��������׳��쳣������ΪĬ��delete�����׳������Բ���Ҫ�ٴ�����
		cout << "destructor.....in...sourceHndle...\n\n";
		
	}
private:
	cSource * m_src;
};
#endif