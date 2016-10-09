#if 0

#define  _CRT_SECURE_NO_WARNINGS
#include "exception_my.h"

int cString::_num = 0;

cString::cString(const cString &str):_chArr(new char[strlen(str._chArr)]){
	//_chArr = str._chArr;  //zwenti....问题
	strcpy(_chArr, str._chArr);
	cout << "copy constructor" << "num:" << ++_num << "\n";
}

cString& cString::operator=(const cString& str){
	//char* tmp(str._chArr);
	char* tmp = new char[strlen(str._chArr)]; //可能跑出异常,但不会资源泄露
	if (tmp != nullptr)
	{
		*tmp = *str._chArr;
	}
	else
		return *this;
	//if (this != &str)
	{
		delete[] _chArr;
		_chArr = tmp;
	}
	return *this;
}
/*
cString& cString::operator=(const cString& str){
	cString *temp = new cString(str._chArr); //错的
	if (this != &str)
	{
		delete[] _chArr;
		//this = static_cast<cString * const>(temp);
		this->_chArr = temp->_chArr;
		//应把str里面的char保存下来，而不是new一个对象
	}
	return *this;
}*/

cString& cString::operator=(const char* cha){
	//delete[] _chArr; //默认delete是不会抛出异常
	if (!cha) cha = "";
	_chArr = strcpy(new char[strlen(cha) + 1], cha);//可能异常3,没关系，不会对任何对象造成问题
	delete[] _chArr; //默认delete是不会抛出异常
	return *this;
}
cString::cString(cString&& str) :_chArr(str._chArr){
	str._chArr = nullptr;

}
cString& cString::operator=(cString&& str){
	if (this != &str)
	{
		delete[] _chArr;
		_chArr = str._chArr;
		str._chArr = nullptr;
	}
	return *this;
}
int main(){
	
	return 0;
}
#endif