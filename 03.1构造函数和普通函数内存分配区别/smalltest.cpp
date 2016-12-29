#if 0
#include <iostream>
#include <time.h>
//#include <sys/resource.h>
//#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pinball.h"

using namespace std;

// Words to add to the hash table
//
const char * inWords[10] = {
	"cauterising",
	"bursar",
	"outbursts",
	"glider",
	"intercity",
	"cartographers",
	"reggae",
	"chivvy",
	"merchantability",
	"felicitation"
};


// Words not in the hash table
//
const char * outWords[10] = {
	"misfiled",
	"opinionated",
	"benefactress",
	"hyperventilating",
	"staged",
	"proprietors",
	"foresee",
	"defrost",
	"spellbinder",
	"womenfolk"
};

//set randLevel
//tip: 此处，为什么ph参数必须是引用，，，否在会是的 对象的 H【i]不是NULL？初始化变了？？？
//为什么？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
//没拷贝构造函数，，浅拷贝的问题吗吗........................
void initPinball(Pinball PH, int degree = 7, int ejectLimt = 14, int level = 2, int seed = 82170){
	//cout << "Init the pinball hash: please set the degree ，ejectLimit, randomLevel(if level = 1 ,please set pseudo random seed)!" << endl;
	//cout << "If use the default settings , please input  -1, otherwise input the degree ，ejectLimit, randomLevel(if level = 1 ,please set pseudo random seed) and separated by space ； such as ： 5 8 1 82170 or 5 8 2" << endl;

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

int main() {

	int slot;

	// change size to increase chance of collision
	//Pinball PH(13);
	Pinball PH(13, 4, 14, 2);
	initPinball(PH, 4, 14, 1, 8210); //为什么这个不是引用个，会导致PH的参数 初始化改变了？？？？
	//在01.1中测试没问题啊？？？？？？？
	cout << "Insert some words\n";
	for (int i = 0; i < 10; i++) {
		try {

			PH.insert(inWords[i]);
			// check if inserted word is in place
			//
			slot = PH.find(inWords[i]);
			if (slot != -1 && strcmp(PH.at(slot), inWords[i]) != 0) {
				cout << "Inserted word not stored at slot = " << slot << endl;
				cout << "   inWords[" << i << "] = " << inWords[i] << endl;
				cout << "   PH.at(" << slot << ") = " << PH.at(slot) << endl;
			}

		}
		catch (PinballHashFull &e) {
			cout << e.what() << endl;
			break;
		}
		catch (...) {
			cout << "Unknown error\n";
		}
	}

	cout << "\n\n";
	PH.printStats();

	cout << "\n\n";
	cout << "Look for inserted words...\n";
	//cout << "\n			insert follow:\n";
	//PH.printStr();
	//cout << "\n			insert follow:\n";

	for (int i = 0; i < 10; i++) {

		slot = PH.find(inWords[i]);
		if (slot < 0) {
			cout << "Inserted word not found: " << inWords[i] << endl;
		}
		else if (strcmp(PH.at(slot), inWords[i]) != 0) {
			cout << "Found word not equal!\n";
		}

	}


	cout << "\n\n";
	cout << "Look for words not inserted (should fail)...\n";
	for (int i = 0; i < 10; i++) {
		slot = PH.find(outWords[i]);
		if (slot > -1) {
			cout << "Found word not stored in hash table: "
				<< PH.at(slot) << endl;
		}
	}


	// Remove two words from the hash table
	int remove1 = 2;
	int remove2 = 6;

	char *str;
	cout << "\n\n";
	cout << "Removing " << inWords[remove1] << endl;
	str = PH.remove(inWords[remove1]);
	//cout <<"remove = " <<  str << endl;
	if (strcmp(str, inWords[remove1]) != 0) {
		cout << "Wrong word removed!" << endl
			<< "   str = " << str << endl
			<< "   inWords[" << remove1 << "] = " << inWords[remove1] << endl;
	}
	free(str);

	cout << "Removing " << inWords[remove2] << endl;
	str = PH.remove(inWords[remove2]);
	if (strcmp(str, inWords[remove2]) != 0) {
		cout << "Wrong word removed!" << endl
			<< "   str = " << str << endl
			<< "   inWords[" << remove2 << "] = " << inWords[remove2] << endl;
	}
	free(str);


	// Look for inserted words again. Two should be missing.
	//
	cout << "\n\n";
	cout << "Look for inserted words...\n";
	for (int i = 0; i < 10; i++) {
		slot = PH.find(inWords[i]);
		if (slot < 0) {
			cout << "Inserted word not found: " << inWords[i] << endl;
		}
		else if (strcmp(PH.at(slot), inWords[i]) != 0) {
			cout << "Found word not equal!\n";
		}
	}


	// Look for words definitely not in the table again.
	// 
	cout << "\n\n";
	cout << "Look for words not inserted (should fail)...\n";
	for (int i = 0; i < 10; i++) {
		slot = PH.find(outWords[i]);
		if (slot > -1) {
			cout << "Found word not stored in hash table: "
				<< PH.at(slot) << endl;
		}
	}


}
#endif
