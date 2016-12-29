#ifndef _PINBALL_H_
#define _PINBALL_H_

#include <string>
#include <stdexcept>
#include <iostream>

using namespace std ;

class PinballHashFull : public std::out_of_range { //insert error used

public:
   PinballHashFull(const string& what) : std::out_of_range(what) { }
} ;


class Pinball {

public:
   Pinball(int n=1019) ;    // default capacity is prime
   ~Pinball() ;

   void insert(const char *str) ;
   int find(const char *str) ;
   const char * at(int index) ;
   //The remove() function removes str from the hash table and returns the pointer. If str is not in the hash table,remove() returns NULL.
   char * remove(const char *str) ; 

   void printStats() ;

   int size() { return m_size ; }

   // add public data members and 
   // public member functions as needed
   Pinball(int n, int degree, int ejectLimit, int level);
   inline char* getValue(int index){
	   return H[index];
   }

   void setRandLevel(int level = 2){
	   m_level = level;
   }

   int getRandLevel(){
	   return m_level;
   }
   void setRandSeed(int seed = 0);

   void initPinballHash(int degree = 7, int ejectLimt = 14, int level = 2, int seed = 821740);
   //jsut test
   inline void printStr(){
	   for (int i = 0; i < m_capacity; ++i)
	   {
		   if (H[i]){
			   cout << H[i] << endl;
		   }
	   }
	   
   }
private:
 
   char ** H ;        // the actual hash table
   int m_size ;       // number of items stored in H
   int m_capacity ;   // number slots allocated in H

   int m_degree ;     // use degree assigned to you
   int m_ejectLimit ; // use ejection limit assigned to you


   // Made inline definition of hashCode() so everyone uses
   // the same function.
   //
   unsigned int hashCode(const char *str) {

      unsigned int val = 0 ; 
      const unsigned int thirtyThree = 33 ;  // magic number from textbook

      int i = 0 ;
      while (str[i] != '\0') {
         val = val * thirtyThree + str[i] ;
         i++ ;
      }
      return val ; 
   }

   // add private data members and 
   // private member functions as needed
   int *m_randSeed;
   int  m_primarySlot;
   int  m_oneInMaxEject;
   int  m_sumEject;
   int  m_level;
   int  m_maxHitPrimSlot;
   int *m_primaSlotHitNum;  

   inline unsigned int getEjectIndex(unsigned int index, int next){
	  //cout << "\nindex ===================" << index << "  " << m_randSeed[index] << " ============= " << next << endl;
	   unsigned int ejectIndex = (unsigned int)myRand(m_randSeed[index]) % m_capacity;
	   //cout << ")))))))))))))))))))))))))))))))myRand  " << ejectIndex << endl;
	   for (int i = 0; i < next; ++i)
	   {
		   ejectIndex = myRand() % m_capacity;
		   //cout << ")))))))))))))))))))))))))))))))myRand  " << ejectIndex << endl;
	   }
	   return ejectIndex;
   }

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
} ;


#endif
