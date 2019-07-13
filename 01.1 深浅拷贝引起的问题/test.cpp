#include "test.h"

CTest::CTest(int n) :m_n(n), m_iarr(NULL), m_string(new string[n]), m_str(NULL){ //����б��ʼ����ʱ��newʧ�����أ���ʹ�ô���new��������03 ���캯���ڴ�й©
	//����˼·,���ڲ���ʼ��
	if (m_string == nullptr)
	{
		m_string = new string[n];
	}
	m_str = new char*[n];
	memset(m_str, NULL, sizeof(char*)*n);
};

CTest::~CTest(){
	if (!m_iarr)
	{
		cout << "delte ..\n";
		delete[] m_iarr;
	}
	if (m_str)
	{
		cout << "delte str \n";
		delete[] m_str;         //
	}
}
CTest::CTest(CTest& test):m_n(test.m_n){
	cout << "depp copy in...\n";
	if (m_iarr){
		m_iarr = new int[m_n];
	}
	if (test.m_str)
	{
		m_str = new char*[m_n];
		memset(m_str, NULL, m_n*sizeof(char*));
	}
	for (int i = 0; i < m_n; ++i)
	{
		if (test.m_str[i])
		{
			//m_str[i] = new char();
			m_str[i] = _strdup(test.m_str[i]);
		}
	}
	cout << "depp copy out ..\n";
}
void CTest::setValue(int i, char* val){
	if (m_str[i] == NULL)
	{
		cout << "null set val \n";
		m_str[i] = val;
	}
	else{
		cout << "str i is not null = " << m_str[i] << endl;
	}
};

int CTest::getValue(int i){
	cout << m_str[i] << endl;
	return i;
};

void CTest::initMemory(int n){
	if (n>0)
	{
		m_iarr = new int[n];
	}
}

void CTest::init(){
	setInt();
	cout << "go out init\n";
}