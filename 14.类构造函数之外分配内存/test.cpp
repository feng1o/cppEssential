#include "test.h"

CTest::CTest(int n) : m_iarr(NULL), m_string(new string[n]){ //����б��ʼ����ʱ��newʧ�����أ���ʹ�ô���new��������03 ���캯���ڴ�й©
	//����˼·,���ڲ���ʼ��
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