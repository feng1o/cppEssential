#if 01
/* File: driver.cpp

Main program used to test Pinball Hash Tables.
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
//#include <sys/resource.h>
//#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "words.h"
#include "Pinball.h"

using namespace std;


// Get amount of user time since the program began in milliseconds.
//
double getmsecs() {
	//struct rusage use ; 
	//struct timeval utime ;

	//getrusage(RUSAGE_SELF, &use) ;
	//utime = use.ru_utime ;
	//return ((double) utime.tv_sec)*1000.0 +  ((double) utime.tv_usec)/1000.0 ;
	return (double)time(NULL);
}


// A "bug-proof" way to call rand() that preserves the state of the
// random seed between calls to rand().
// Set the random seed by passing a non-zero parameter.
//
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

//set randLevel
void initPinball(Pinball &PH, int degree = 7, int ejectLimt = 14, int level = 2, int seed = 82170){
	//cout << "Init the pinball hash: please set the degree £¬ejectLimit, randomLevel(if level = 1 ,please set pseudo random seed)!" << endl;
	//cout << "If use the default settings , please input  -1, otherwise input the degree £¬ejectLimit, randomLevel(if level = 1 ,please set pseudo random seed) and separated by space £» such as £º 5 8 1 82170 or 5 8 2" << endl;

	//int flag = -100;
	//cin >> flag;
	//if (-1 != flag)
	//{
	//	degree = flag;
	//	cin >> ejectLimt >> level;
	//	if (level == 1) cin >> seed;
	//}
	PH.initPinballHash(degree, ejectLimt, level, seed);
	//cout << "The initialization is : " << endl;
	//cout << "		degree = " << degree << endl;
	//cout << "		ejectLimt = " << ejectLimt << endl;
	//cout << "		level = " << level << endl;
	//if (level == 1)
	//	cout << "		seed = " << seed << endl;
	//cout << endl << endl;
}

// Exercise the Pinball Hash table with size slots
// inserting reps items.
//
void test(int size, int reps) {

	int index;
	int slot;
	double startTime, stopTime;

	Pinball PH(size);
	//   initPinball(PH, 7, 14, 2, 82170);
	// initPinball(PH, 7, 14, 1, 82170 * 37);
	initPinball(PH, 20, 14, 1, 82170 * 3);

	startTime = getmsecs();

	// Insert reps randomly chosen items
	//
	for (int i = 0; i < reps; i++) {

		// don't choose items already in the hash table
		//   do { 
		//      index = myRand() % numWords ;
		//cout << "-----------find word index = " << index << endl;
		//slot = PH.find(words[index]);
		//cout << "try insert i= " << i << "  test...................................SLOT = " << slot << endl;
		//if (slot > -1)
		//{
		// cout << "+++++++++++++++++++++++++++++++++++++++++++++  " <<words[index] << " - " << PH.getValue(slot) << endl;
		//}
		//
		//   } while(slot > -1) ;
		if (PH.find(words[i]) > -1) continue;
		index = i;
		try {

			//cout << "before insert index= " << index << "  test..SLOT=" << slot << endl;
			PH.insert(words[index]);  // might throw exception
			//PH.insert(words[22762]);  // might throw exception
			cout << "string " << i << " = " << words[index] << "  insert ok \n\n";

			// double check that inserted items were stored properly
			// for debugging.

			/*
			slot = PH.find(words[index]) ;
			if (slot >=0 && strcmp(PH.at(slot),words[index]) != 0) {
			cout << "Inserted word not stored at slot = " << slot << endl ;
			cout << "   words[" << index << "] = " << words[index] << endl ;
			cout << "   PH.at(" << slot << ") = " << PH.at(slot) << endl ;
			}
			*/

		}
		catch (PinballHashFull &e) {
			cout << e.what() << endl;
			break;
		}
		catch (...) {
			cout << "Unknown error\n";
		}
	}

	stopTime = getmsecs();
	printf("Elapsed time = %.3lf milliseconds\n", stopTime - startTime);

	PH.printStats();
}


int main() {
	//freopen("out.txt", "w+", stdout);
	// set random seed to wall clock time in milliseconds
	//

	/*struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;*/
	long int ms = (long int)time(NULL);
	printf("Random seed set to: %ld\n\n", ms);
	myRand(ms);
	srand(ms * 37);   // other uses

	// When debugging/developing, uncomment a line below and
	// use a fixed random seed.
	//
	// myRand(82170) ; srand(82170*37) ;
	// myRand(3170325890) ; srand(3170325890*37) ;
	// myRand(9132919912) ; srand(9132919912*37) ;
	myRand(82170); srand(82170 * 37);
	test(5003, 4000);   // >5,000 slots, ~80% full
	printf("\n\n");

	//test(10037,8000) ;  // >10,000 slots, ~80% full
	//printf("\n\n") ;

	//test(20101,16000) ;  // >20,000 slots, ~80% full
	//printf("\n\n") ;

	return 0;
}
#endif



