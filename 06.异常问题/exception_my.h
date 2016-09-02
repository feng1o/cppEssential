
#ifndef  _H_EXCEPTION_MY
#define  _H_EXCEPTION_MY

#include "string"
#include "iostream"
#include "memory"

using namespace std;

class cString {
public:
	cString(char* charr) : _chArr(charr){
		cout << "char* constructor" << "num:" << ++_num << "\n";
	};
	cString() :_chArr(""){
		cout << "default constructor" << "num:" << ++_num << "\n";
	};
	cString(const cString &str);
	cString&  operator=(const cString& str);
	cString& operator=(const char* cha);

	cString(cString&& str);
	cString& operator=(cString&& str);

	~cString(){ delete[] _chArr; };
private:
	char* _chArr;
	static int  _num;
};

#endif