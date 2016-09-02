#include "iostream"
#include "src.h"
#include "srchandle.h"

int main1(){
	cSource *src_1 = new cSource("src_1....");
	std::cout << "....\n";
	throw 2;  //src资源无法释放了
	delete src_1;
	return 0;
}

int main2(){
	cResHandle srcHandle(new cSource("..."));
	//cResHandle *psrcHandle = new cResHandle(new cSource("..."));
	throw 2;
	cout << "....delete.....\n";
//	return 0;
}

int main(){
	try{
		main1();
	}
	catch (...){
		cout << "cathc...\n";
	}
	cout << ".....不会调用析构、资源泄露..........main..........\n\n";


	//
	try{
		main2();
	}
	catch (...){
		cout << "cathc...\n";
	}
	cout << "...............main..........\n";
	return 0;
}