#ifndef  _TEST_H_
#define _TEST_H_
#include "iostream"
#include "string"

using namespace std;

class CTest {
public:

	CTest(int n = 10);
	CTest(CTest& test);  //?????????????
	~CTest();

	void initMemory(int n);
	int getValue(int i);;
	void setValue(int i, char* val);
	void init();

	void setInt(){
		for (int i = 0; i < m_n; ++i)
		{
			m_iarr[i] = i + 100;
		}
	}
private:
	int *m_iarr;
	char** m_str;
	string *m_string;
	int m_n;
};
#endif