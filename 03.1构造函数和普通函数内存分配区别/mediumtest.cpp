#if 0
#include <iostream>
#include <time.h>
//#include <sys/resource.h>
//#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "words.h"
#include "Pinball.h"

using namespace std ;


// A "bug-proof" way to call rand() that preserves the state of the
// random seed between calls to rand().
// Set the random seed by passing a non-zero parameter.
//
int myRand(int seed=0) {

   // static local variables persist between calls
   static int savedSeed ;   

   if (seed) savedSeed = seed ;

   int othersSeed = rand() ;  // save other people's seed
   srand(savedSeed) ;         // restore my seed
   int result = rand() ;
   savedSeed = result ;       // save for next time
   srand(othersSeed) ;        // restore other people's
   return result ;
}
//set randLevel
void initPinball(Pinball PH, int degree = 7, int ejectLimt = 14, int level = 2, int seed = 82170){
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
int main() {

   int slot ;
   int N = 1117 ;

   /*struct timeval tp;
   gettimeofday(&tp, NULL);
   long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;*/
   long int ms = (long int)time(NULL);
   printf("Random seed set to: %ld\n\n", ms);
   myRand(ms);

   // Uncomment to use same random seed each time
   //
   // myRand(8781035) ;

   myRand(8781035);
   Pinball PH ;

   //initPinball(PH, 7, 14, 2, 82170);
   int index ;
   const int reps=750 ;

   cout << "Insert some words\n" ;

   int saveIndices[reps] ;  // array to remember which words were picked


   // Pick some words from global words[] array to insert in the hash table. 
   // Pick words in index 0 .. 9999
   //
   int nNext = 0;
   for (int i=0 ; i < reps ; i++) {
      try {
         index = myRand() % 10000 ;  // 0 .. 9999
         saveIndices[i] = index ;    // save which words were picked
		 nNext = i;
         PH.insert(words[index]) ;

         // check that inserted words are really there
         //
         slot = PH.find(words[index]) ;
         if (slot != -1 && strcmp(PH.at(slot),words[index]) != 0) {
            cout << "Inserted word not stored at slot = " << slot << endl ;    
            cout << "   words[" << index << "] = " << words[index] << endl ;
            cout << "   PH.at(" << slot << ") = " << PH.at(slot) << endl ;
         }

      } catch (PinballHashFull &e) {
         cout << e.what() << endl ;
		 /* while (i < reps)
			  saveIndices[++i] = 1;*/
         break ;
      } catch (...) {
         cout << "Unknown error\n" ;
      }
   }

   cout << "\n\n" ;
   PH.printStats() ;


   // Check again that words we inserted are actually in the table.
   //
   cout << "\n\n" ;
   cout << "Look for inserted words...\n" ;
	//for (int i = 0; i < reps; i++) { 
	for (int i = 0; i < nNext; i++) {
      index = saveIndices[i] ;  // recover words that were picked
      slot = PH.find(words[index]) ;
      if (slot < 0) {
         cout << "Inserted word not found: " << words[index] << endl  ;
      } else if (strcmp(PH.at(slot),words[index]) != 0) {
          cout << "Found word not equal!\n" ;    
      }
   }



   // Check some words that are definitely not in the hash table
   // Words randomly picked from global words[] array in the
   // range 15000 .. 24999.
   // 
   cout << "\n\n" ;
   cout << "Look for words not inserted (should fail)...\n" ;
   for (int i=0 ; i < reps ; i++) {
      index = ( (myRand() % 10000) + 15000 ) % numWords ;   // 15000 ..  24999
      slot = PH.find(words[index]) ;
      if (slot > -1) {
         cout << "Found word not stored in hash table: " 
              << PH.at(slot) <<  endl ;
         cout << "   index = " << index << endl ;
         cout << "   slot = " << slot << endl ;
      }
   }


   // Pick some words to be removed from the hash table
   //
   char *str ;
   cout << "\n\n" ;
   cout << "Remove some words ...\n" ;
   for (int j = 0; j < 20 && j < nNext; j++) {
 //for (int j = 0; j < 20 ; j++) {
      index = myRand() % reps ;
      str = PH.remove(words[saveIndices[index]]) ;  // recover words that were picked
      cout << "Removing " << words[saveIndices[index]] << endl ;

      if (str != NULL && strcmp(str,words[saveIndices[index]]) != 0) {
         cout << "Wrong word removed!" << endl
              << "   str = " << str << endl 
              << "   words[" << saveIndices[index] << "] = " 
                 << words[saveIndices[index]] << endl ;
      }
      free(str) ;
   }

  
   // Look for words in the hash table again.
   // The words we removed should be missing.
   //
   cout << "\n\n" ;
   cout << "Look for inserted words...\n" ;
   for (int i = 0; i < reps && i < nNext; i++) {
// for (int i = 0; i < reps; i++) {
      index = saveIndices[i] ;
      slot = PH.find(words[index]) ;
      if (slot < 0) {
         cout << "Inserted word not found: " << words[index] << endl  ;
      } else if (strcmp(PH.at(slot),words[index]) != 0) {
          cout << "Found word not equal!\n" ;    
      }
   }


   // One more time, check words we know are not in the hash table.
   // None of these should be found.
   //
   cout << "\n\n" ;
   cout << "Look for words not inserted (should fail)...\n" ;
   for (int i=0 ; i < reps ; i++) {
      index = ( (myRand() % 10000) + 15000 ) % numWords ;    // 15000 to 24999
      slot = PH.find(words[index]) ;
      if (slot > -1) {
         cout << "Found word not stored in hash table: " 
              << PH.at(slot) << endl ;
      }
   }

}

#endif