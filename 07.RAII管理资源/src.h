#ifndef _RESOURCES_H_
#define _RESOURCES_H_

#include "iostream"
#include "memory"
#include "string"

using namespace std;

class cSource{
public:
	cSource() :m_str(nullptr){
		cout << "constructor...in..src...\n";
	};
	cSource(const string& str) :m_str(new string(str)){
		cout << "constructor...in..src...\n";
	};

	cSource(const cSource& src) :m_str(new string(*src.m_str)){
	};
	~cSource(){
		cout << "destructor.....in...source...\n";
	}
	string* getPstr() const {
		return m_str;
	}
private:
	string*  m_str;
};
#endif