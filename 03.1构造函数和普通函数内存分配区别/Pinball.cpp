#define  _CRT_SECURE_NO_WARNINGS
#include "Pinball.h"

//construction
//tip:w问题：-----------为什么main里面调用init的时候，传入对象必须是引用？？？难道是因为没拷贝构造函数，浅拷贝了？？
/*1. 没使用列表初始化对几个new，malloc对象分配内存。。这样浪费资源
2.实际上都没对象，肯定不需要判定是不是NULL，，函数体有多余的
3.initPinballHash里面也可以对这个对象进行内存分配，，也就是把函数体里的搬到那个里面也是ok的，，，

'注意
1.memset的时候是针对字节做初始化的，所以，malloc(sizeof(x) * size)的，必须是memset(&addr, 'ASCII', size*sizeof(x))不可是size代替；http://blog.csdn.net/my_business/article/details/40537653
2.strcmp(constr char* str1, const char* str2)传入的参数不可以是NULL，如果是会崩溃，库函数不会做检测；
3.strdup(const char* src)会在函数里面调用malloc，所以，使用后有时候需要free，一般在一直有效的时候使用它，不用free也不内存邪路
4.c++里面的类，能否在构造函数之外给他 元素 new空间？然后后面还能访问呢？  可以的；那么与在构造函数里面new内存区别是什么？---wenti :构造函数应该适用列表初始化方式new，而不是在内部new，故，此方法是没区别，但是，方法不对！！！
5.c++构造函数列表初始化的时候，比如对元素new内存，如果不适用列表初始化就会开销增大，不需要判定是不是NULL，因为创建新对象，不是废话吗！！！切记！，，列表初始化
*/
Pinball::Pinball(int n) :m_size(0), m_capacity(n), H(NULL), m_degree(7), m_ejectLimit(14), m_randSeed(NULL), m_oneInMaxEject(0), m_sumEject(0),m_primarySlot(0),m_level(2), m_maxHitPrimSlot(0), m_primaSlotHitNum(NULL){
	if (H == NULL)
	{
		H = (char **)malloc(sizeof(char*) * m_capacity);
		if (!H)
		{
			throw  PinballHashFull("malloc error!\n");
		}
		memset(H, NULL, m_capacity*(sizeof(char*))); //initialize //注意这个memset是按字节的，故，必须是sizeof（）求得大小，，，，不可直接capacity
	}
	if (m_randSeed == NULL)
	{
		m_randSeed = (int*)malloc(sizeof(int)*m_capacity);
		if (!m_randSeed){
			throw PinballHashFull("malloc error!\n");
		}
		memset(m_randSeed, -1, m_capacity*sizeof(int));//set by byte 
	}
	if (m_primaSlotHitNum == NULL)
	{
		m_primaSlotHitNum = (int*)malloc(sizeof(int)*m_capacity);
		if (!m_primaSlotHitNum){
			throw PinballHashFull("malloc error!\n");
		}
		memset(m_primaSlotHitNum, 0, m_capacity*sizeof(int));//set by byte 
	}
}

//construction
Pinball::Pinball(int n, int degree, int ejectLimit,  int level) :m_size(0), m_capacity(n), H(NULL), m_degree(degree), m_ejectLimit(ejectLimit), m_randSeed(NULL), m_oneInMaxEject(0), m_sumEject(0), m_primarySlot(0), m_level(level), m_maxHitPrimSlot(0), m_primaSlotHitNum(NULL){
	if (H == NULL)
	{
		H = (char **)malloc(sizeof(char*) * m_capacity);
		if (!H)
		{
			throw  PinballHashFull("malloc error!\n");
		}
		memset(H, NULL, m_capacity*(sizeof(char*))); //initialize
	}
	if (m_randSeed == NULL)
	{
		m_randSeed = (int*)malloc(sizeof(int)*m_capacity);
		if (!m_randSeed){
			throw PinballHashFull("malloc error!\n");
		}
		memset(m_randSeed, -1, m_capacity*sizeof(int));//set by byte 
	}
	if (m_primaSlotHitNum == NULL)
	{
		m_primaSlotHitNum = (int*)malloc(sizeof(int)*m_capacity);
		if (!m_primaSlotHitNum){
			throw PinballHashFull("malloc error!\n");
		}
		memset(m_primaSlotHitNum, 0, m_capacity*sizeof(int));//set by byte 
	}
}

//destructor
Pinball::~Pinball(){
	if (H){
		free(H);
	}
	if (m_randSeed){
		free(m_randSeed);
	}
	if (m_primaSlotHitNum){
		free(m_primaSlotHitNum);
	}
}


//insert methord
//为什么，这个的 static的nEJECT在重新调用insert的时候没有更新？？？？
void Pinball::insert(const char *str){
	static int nEject = 0;
	static int maxHitPrimSlot = 0;
	unsigned int index = static_cast<unsigned int>(hashCode(str)) % m_capacity;
	//cout << "hashcode ===========================================" << index << endl;
	unsigned int back_index = index;
	if (2 == getRandLevel()){
		if (m_randSeed[index] == -1){
			//m_randSeed[index] == rand();// less than 1 second will get zhe sam result！！！
			m_randSeed[index] = index + 1;  //tip:  this seed must not 0..................
		}
	}
	if (at(index) != NULL)
	{
		//cout << "xxxxxxxxxxxxxxxxxxxxxxxxxx\n";
		m_maxHitPrimSlot = ++m_primaSlotHitNum[index] > m_maxHitPrimSlot ? m_primaSlotHitNum[index] : m_maxHitPrimSlot;
		index = (unsigned int)(myRand(m_randSeed[index]) % m_capacity);
		for (int i = 0; i < m_degree; ++i)
		{
			if (at(index) == NULL)
			{
				++m_size;
				m_sumEject += nEject;
				nEject = 0;
				//H[index] = const_cast<char*>(str);
				H[index] = _strdup(str);
				return;
			}
			else
				index = static_cast<unsigned int>((myRand() % m_capacity));
		}
		// need eject
		index = index % m_degree;
		unsigned int ejectIndex = getEjectIndex(back_index, index);
		//cout << "eject index= " << ejectIndex << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> " << H[ejectIndex] << "\n";
		++nEject;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++neject = " << nEject<< endl;
		if (nEject > m_oneInMaxEject) m_oneInMaxEject = nEject;
		if (nEject == m_ejectLimit){
			m_sumEject += nEject;
			nEject = 0;
			//cout << "insert go out ........................exception   ........\n";
			throw PinballHashFull("hast table is full~!\n");
		}
		//const char* nStr = H[ejectIndex];//eject str
		char* nStr = _strdup(H[ejectIndex]);
		//char nStr[100]="a";
		//cout << nStr << endl;
		//strcpy(nStr, H[ejectIndex]);
		free(H[ejectIndex]);          //free重要，，，，，，而且，这个题必须使用strdup插入，，否则，，可能会导致多个同，或者free同一个多次，，，
		//H[ejectIndex] = const_cast<char*>(str);
		H[ejectIndex] = _strdup(str);
		//cout << H[ejectIndex] << "   eject over....going to new insert ???????????????????????????????????? " << "\n";
		insert(nStr);
	
	}
	else{
		++m_primarySlot;
		++m_size;
		m_sumEject += nEject;
		nEject = 0;
		H[index] = _strdup(str);
		//H[index] = const_cast<char*>(str);
		//cout << "insert go out ...........................last   .....\n";
	}
}

//find
int Pinball::find(const char *str){
	#if 1
int index = static_cast<int>(hashCode(str) % m_capacity);
	if (m_level == 2 && m_randSeed[index] == -1) //no key insert;
		return -1;
	//cout << "begin find =======================" << index << endl;

	//if (H[index] == NULL)
	//{
	//	cout << "nulllllllllllllllllllllll\n\n";
	//}
	//if (m_randSeed[index] == -1)
	//	cout << "-1-1-1-1-1-1-1-1-1-1-1\n\n";

	if (H[index] != NULL && str != NULL && strcmp(str, H[index]) == 0)
		return index;
	index = myRand(m_randSeed[index]) % m_capacity;
	for (int i = 0; i < m_degree; ++i)
	{
		//cout << "i=" << i << " index= "<< index << endl;
		if (H[index] != NULL && str != NULL && strcmp(str, H[index]) == 0)
			return index;
		index = myRand() % m_capacity;
	}
	//cout << "return from find....\n";
#endif
	//for (int i = 0; i < m_capacity; ++i)
	//{
	//	if (H[i] != NULL && str != NULL && strcmp(str, H[i]) == 0)
	//		return i;
	//}
	return -1;
}

//at
const char* Pinball::at(int index){
	if (0 > index || m_capacity <= index){
		cout << "out of range index ======= " << index << endl;
		throw PinballHashFull("out of range !");
	}

	return H[index];
}

//remove
char* Pinball::remove(const char *str){
	int index = find(str);
	if (index == -1)
		return NULL;
	else{
		char* rstr = H[index];
		H[index] = NULL;
		--m_size;
		return rstr;
	}
}

//printStats
void Pinball::printStats(){
	cout << "Hash statistics report: " << endl;
	cout << "   randomness level = pseudo-random" << endl;
	cout << "   capacity = " << m_capacity << " " << endl;
	cout << "   size = " << m_size << " " << endl;
	cout << "   degree = " << m_degree << " " << endl;
	cout << "   ejection limit = " << m_ejectLimit << " " << endl;
	cout << "   number of primary slots  = " << m_primarySlot << endl;
	cout << "   average hits to primary slots = " << static_cast<double>(m_size) / m_primarySlot << endl;
	cout << "   maximum hits to primary slots = " << m_maxHitPrimSlot << endl;
	cout << "   total number of ejections = " << m_sumEject << endl;
	cout << "   maximum number of ejections in a single insertion = " << m_oneInMaxEject << endl;
	return;
}

//set seed
void Pinball::setRandSeed(int seed){
	m_randSeed[0] = myRand(seed);
	for (int i = 1; i < m_capacity; ++i)
	{
		m_randSeed[i] = myRand();
	}
}

void Pinball::initPinballHash(int degree, int ejectLimt, int level, int seed){
	m_degree = degree;
	m_ejectLimit = ejectLimt;
	m_level = level;
	if (m_level == 1)
	{
		setRandSeed(seed);
	}
	//cout << "init ok\n";
}