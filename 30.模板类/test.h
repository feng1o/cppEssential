#ifndef _TEST_H
#define _TEST_H
#include "iostream"
#include "exception"

template<typename T, int m_size>
class CTest{
public:
	CTest() :m_iNum(0), m_array(nullptr){
		if (nullptr == m_array)
			m_array = new T[m_size];
		if (nullptr == m_array)
			throw std::exception("bad alloc~!");
	};
	void Print(){
		std::cout << "num==" << m_iNum << std::endl;
		std::cout << "size=" << m_size << std::endl;
	};
private:
	int m_iNum;
	T*  m_array;

};
#endif