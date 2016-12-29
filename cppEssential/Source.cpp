#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

using namespace std;

int myRand(int seed = 0) {

	// static local variables persist between calls
	static int savedSeed;

	if (seed) savedSeed = seed;

	int othersSeed = rand();  // save other people's seed
	srand(savedSeed);         // restore my seed
	int result = rand();
	savedSeed = result;       // save for next time
	srand(othersSeed);        // restore other people's
	return result;
}
void mySwap( char** str1,  char** str2){
	std::swap(*str1, *str2);

}

int main(){
	//freopen("out.txt", "w+", stdout);
	myRand(82170); srand(82170 * 37);
	while (1){
		cout << myRand() << endl;
	}
	char a[][5] = { "abc", "bcd", "efg", "klj" };
	char *str = static_cast<char*>(a[3]);
	cout << a[0] << " " << a[1] << endl;
	cout << str << endl;
	cout <<"strcmp=" << strcmp("abc", (char*)NULL) << endl;
	//myRand(1000);
	cout << myRand(10) << endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << myRand() << endl;
	}
	 char* str1 = "abc";
	char* str2 = "222222";
	std::cout << str1 << "   " << str2 << endl;
	mySwap(&str1, &str2);
	//std::swap(str1, str2);
	std::cout << str1 << "   " << str2 << endl;

	/*clock_t clk = clock();
	cout << "clock=" << clk << endl;
	int **p = nullptr;
	p = new int*;
	if (p == nullptr)
	{
	cout << "Nullptr \n";
	}
	*p = new int(2);
	cout << "p" << **p << endl;


	char** sstr = (char**)malloc(10);
	memset(sstr, 0, 10);
	*sstr = "abc";
	sstr[1] = "11111";
	cout << *sstr << " \n" << sstr[1] << endl;*/
	return 0;
}