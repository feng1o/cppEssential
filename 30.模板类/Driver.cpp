//tip:
/*
1.MinHeap、MaxHeap里面的拷贝构造函数问题，，
2.heap里面的拷贝构造函数实现有无问题
3.有些应该在头文件里面实现，不应该在cpp，因为是模板~！做inline；
4.非模板类型参数问题，是要传入可变的呢？如果不是固定的10000呢？

5.这个minhep和 MaxHeap未实现，如何做？
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

#include "PinHit.h"
#include "Heap.h"
#include "MinHeap.h"
#include "MaxHeap.h"
#include "iomanip"
// #include <unistd.h>
#include "windows.h"
// global variable for type of heap
std::string heapType = "--max";
//forward declare so I can define it below main
void printGreeting();

std::vector<PinHit> ReadPins(char* fileName, int* totalHits);

template<class T, int m_size>
Heap<T, m_size>* BuildHeap(std::vector<T> PinHits, int slots);

// provided
template<class T, int m_size>
int Hack(Heap<T, m_size>* heap, std::vector<T> PinHits, int totalHits);

int main(int argc, char* argv[]) {

	printGreeting();
	//if (argc != 3)
	//{
	//	std::cerr << "input arguments error \n";
	//	exit(EXIT_FAILURE);
	//}
	//std::string openFile = argv[1];
	//heapType = argv[2];
	int totalHits = 0;
	std::vector<PinHit> pinVec = ReadPins("Input1.txt", &totalHits);
	//std::vector<PinHit> pinVec = ReadPins(const_cast<char*>(openFile.c_str()), &totalHits);
	int  minMaxFlag = 1;
	if (heapType != "--max")
		minMaxFlag = -1;
	Heap<PinHit, 10000> *heap = BuildHeap<PinHit, 10000>(pinVec, minMaxFlag);

    //test
	//PinHit rpin = heap->Remove();
	//std::cout << "\n" << rpin.GetKey() << " " << rpin.GetValue() << std::endl << std::endl;

    //std::cout << Hack<PinHit, 10000>(heap, pinVec, totalHits) << std::endl;
    

    std::cout << "Print by funciton Hack!\n";
	bool actTenFlag[10] = { false };
	int hitNum = 0;
	int hitOk = 0;
	for (int i = 0; i < 10; ++i){
        Sleep(1000);
		int hit = Hack<PinHit, 10000>(heap, pinVec, totalHits);
		printf("hit = %d\n",hit);
		if (hit){
			hitOk++;
			actTenFlag[i] = true;
		}
		hitNum += hit;
	}
    std::cout <<"\n\nBelow is the results of ten tests:" << std::endl;
	std::cout << "Acts Hacked (10 runs): ";
	for (int i = 0; i < 9; ++i)
	{
		std::cout << actTenFlag[i] << ",";
	}
	std::cout << actTenFlag[9] << std::endl;
	std::cout << "Avg (accounts/run): " << (static_cast<double>(hitOk) / 10) << std::endl;
	std::cout << "Hits in 1008 Attempts: " << hitNum << std::endl;
	std::cout << "Hits (total): " << totalHits << std::endl;
	//printf("Probability of Hacking: %.2f%%\n", (double)hitNum / totalHits * 100);
	std::cout << "Probability of Hacking: " << static_cast<double>(hitNum) / totalHits * 100 << "%" << std::endl;
	return EXIT_SUCCESS;
}

// prints your name and section
void printGreeting() {
	std::cout << "Gene Burchette, Section 05" << std::endl;
}

// implement these two functions
std::vector<PinHit> ReadPins(char* fileName, int* totalHits) {
	std::vector<PinHit> pinVec(10000);
	for (int i = 0; i < 10000; ++i){
		pinVec.push_back(PinHit(i, 0));
	}
	std::ifstream  ifs(fileName, std::ifstream::binary);
	if (ifs){
		//ifs.seekg(0, ifs.end);
		//std::cout << "IFS.tellg() =" << ifs.tellg() << endl;
		while (ifs){
			int num = -1;
			ifs >> num;
			//cout << num << endl;
			if (num < 10000 && num > -1){
				pinVec[num].SetKey(num);
				pinVec[num].IncrementHits();
				*totalHits += 1;
			}
		}
		ifs.close();
	}
	else{
        std::cout << "openfile error \n";
	}
	return pinVec;
}

template<class T, int m_size>
Heap<T, m_size>* BuildHeap(std::vector<T> PinHits, int slots) {
	Heap<T, m_size>  *heap = new Heap<T, m_size>[m_size];
	//std::cout << heap->GetSize() << std::endl;
	if (slots == 1)
	{
		heap->SetFlag(true);
	}
	else{
		heap->SetFlag(false);
	}
	for (int i = 0; i < PinHits.size(); ++i)
	{
		if (PinHits[i].GetValue() != 0)
		{
			//std::cout << PinHits[i].GetKey() << "......" << PinHits[i].GetValue() << std::endl;
			heap->Insert(PinHits[i]);
		}
	}
	return heap;
}

// provided
template<class T, int m_size>
int Hack(Heap<T, m_size>* heap, std::vector<T> PinHits, int totalHits) {

int UPPER_BOUND = totalHits; // used for failsafes

	/*
	* His fictional bank with fictional cards and 
	* "normal pins" will allow you to incorrectly attempt 
	* to access his card 3 times per hour. You have from 
	* the start of the assignment to the end to hack as 
	* many accounts as possible (14 days * 24 hr/day * 3 
	* attempts/hr = 1008 attempts per card)
	*/
	int MAX_ATTEMPTS = 1008;

	int hackAttemptsLeft = MAX_ATTEMPTS;
	int successfulHacks = 0;

  	srand (time(NULL)); // seeds our random generator with the current time  	
	int randomNumHits = rand() % totalHits; // generates a random hit between 0 and total hits	
	//randomNumHits = 0; // change this if you want to hardcode in your hits for a specific pin
	int curHits = 0; // our variable for crawling
	int randomIndex = -1; // the index where our new random pinhit lives
	int newHits = 0; // number of hits in new "random" pin
	int failSafe = 0; // always good to have one of these in what could be an infinite loop

	/* 
	* Linearly searches through PinHits until
	* we've accrued enough hits to reach our random hits
	* which will then determine the next pin to try to hack.
	* We use newHits to make sure we don't pick a random pin
	* that's not in our heap. 
	*/
	PinHit curPinHit;
	while (newHits == 0 && failSafe < UPPER_BOUND) {

		for (unsigned int i = 0; i < PinHits.size() && curHits <= randomNumHits; i++) {
			curHits += PinHits[i].GetValue();
			randomIndex = i;
		}
		// should have found the random pin by now
		curPinHit = PinHits[randomIndex];
		newHits = curPinHit.GetValue(); // make sure it's actually in our heap
		std::cout << "Random Pin: [" << curPinHit.GetKey() << ", " << curPinHit.GetValue() << "] found!" << std::endl;
		failSafe++;
	}

	// let's make a copy of the heap so we don't modify the original.
	Heap<T, m_size>* heapCopy = new Heap<T, m_size>(*heap);

	failSafe = 0;

	PinHit defaultPin;

	// exit once hacking 10000 accounts, either a hacking prodigy or something is wrong
	int MAX_NUM_HACKS = 10000;

	while (0 < hackAttemptsLeft && successfulHacks < MAX_NUM_HACKS) {

		// grabs our root
		PinHit topOfHeap = heapCopy->Remove();
		if (topOfHeap == defaultPin)
			break;

		//std::cout << topOfHeap.GetKey() << ", " << topOfHeap.GetValue() << " our last attempt" << std::endl;
        
		if (hackAttemptsLeft == 1)
		std::cout << topOfHeap.GetKey() << ", " << topOfHeap.GetValue() << " our last attempt" << std::endl;

		hackAttemptsLeft--;

		// account was hacked!
		if (topOfHeap == curPinHit) {
			std::cout << "We got them!" << std::endl;
			successfulHacks++;

			// reset our heap
			heapCopy = new Heap<T, m_size>(*heap);

			// reset
			hackAttemptsLeft = MAX_ATTEMPTS;
			randomNumHits = rand() % totalHits;
			curHits = 0;
			randomIndex = -1;
			newHits = 0;
			failSafe = 0;
			while (newHits == 0 && failSafe < UPPER_BOUND) {

				for (unsigned int i = 0; i < PinHits.size() && curHits <= randomNumHits; i++) {
					curHits += PinHits[i].GetValue();
					randomIndex = i;
				}
				// should have found the random pin by now
				curPinHit = PinHits[randomIndex];
				newHits = curPinHit.GetValue(); // make sure it's actually in our heap
				std::cout << "Random Pin: [" << curPinHit.GetKey() << ", " << curPinHit.GetValue() << "] found!" << std::endl;
				failSafe++;
			}

			std::cout << "Valid Random Pin: " << curPinHit.GetKey() << " found!" << std::endl;
		}
	}	
	

	return successfulHacks;

}
