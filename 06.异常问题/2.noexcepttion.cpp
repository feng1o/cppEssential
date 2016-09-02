#if 0
#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

#include "iostream"
#include "exception"

using namespace std;

void fun_1()  NOEXCEPT {
	try{
		throw 2;
	}
	catch (int i){
		cout << "catch " << i << endl;
		throw;
	}
}

void fun_2() NOEXCEPT(NOEXCEPT(fun_1())) {
	try{
		throw 2;
	}
	catch (int i){
		cout << "catch " << i << endl;
		throw;
	}
}

int main2(){
	try{
		fun_1();
	}
	catch (...){
		cout << "catch ...main...\n";
	};


	fun_2();  //Î´²¶»ñÒì³£ ³ÌÐò´íÎóÖÕÖ¹
	cout << "ok???";
	return 0;
}
#endif