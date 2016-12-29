#include "stdio.h"
#include "stdlib.h"
#include "iostream"

using namespace std;


int myRand1(int seed = 0) {

	// static local variables persist between calls
	static int savedSeed;

	if (seed) savedSeed = seed;

	int othersSeed = rand();  // save other people's seed
	srand(savedSeed);         // restore my seed
	int result = rand();
	savedSeed = result;       // save for next time
	srand(othersSeed + 2);        // restore other people's
	return result;
}

int myRand2(){
	return rand();
}
int main(){
	srand(12);
	for (int i = 0; i < 10; ++i)
		cout << rand() % 1000 << endl;
	srand(12);
	for (int i = 0; i < 10; ++i)
	{
		cout << myRand2()%1000 << endl;
	}

	myRand1(122);
	for (int i = 0; i < 10000; ++i)
	{
		cout << myRand1() << "\t" ;
	}
	return 0;
}