#include "test.h"

CTest::CTest(int n) : m_iarr(NULL), m_string(new string[n]){ //如果列表初始化的时候new失败了呢，课使用代理new方法，看03 构造函数内存泄漏
	//错误思路,在内部初始化
	if (m_string == nullptr)
	{
		m_string = new string[n];
	}
};

CTest::~CTest(){
	if (!m_iarr)
	{
		cout << "delte ..\n";
		delete[] m_iarr;
	}
}

void CTest::setValue(int i, int val){
	m_iarr[i] = val;
};

int CTest::getValue(int i){
	return m_iarr[i];
};

void CTest::initMemory(int n){
	if (n>0)
	{
		m_iarr = new int[n];
	}
}