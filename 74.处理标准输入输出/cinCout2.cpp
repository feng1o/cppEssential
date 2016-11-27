#if 0
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "iomanip"
#include "stdio.h"
#include "string.h"
using namespace std;

int main()
{
	int numN, numK;
	int saveN, saveK;
	int *numArray = nullptr;
	while (true)
	{
		cin >> numN >> numK;
		if (numK == 0 && numN == 0)
			break;
		saveN = numN;
		saveK = numK;
		numArray = new int[numN]{0};
		int tmp;
		for (int i = 0; i < numN;  ++i)
		{
			cin >> tmp;
			numArray[i] = tmp;
		}
		cout << "numk = " << numArray[saveK] << std::endl;
	}
	
	for (int i = 0; i < saveN; ++i)
	{
		cout <<left <<  setw(3) << numArray[i] << endl;
	}

	return 0;
}
#endif