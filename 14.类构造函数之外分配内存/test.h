#ifndef  _TEST_H_
#define _TEST_H_
#include "iostream"
#include "string"

using namespace std;

class CTest {
public:

	CTest(int n=10);
	~CTest();

	void initMemory(int n);
	int getValue(int i);;
	void setValue(int i, int val);
private:
	int *  m_iarr;
	string *m_string;
};
#endif