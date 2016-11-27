#if 0
#include "iostream"
#include "string"
#include "vector"
#include "memory"
#include "bitset"
#include "tuple"

using namespace  std;
class AdBEntry
{
public:
	AdBEntry() :theName(), theAddress(), numTimeConsulted(1){ cout << "default " << numTimeConsulted << endl; }
	AdBEntry(string tnme, string taddr, int num) :theAddress ( taddr),theName ( tnme),
	numTimeConsulted (num)
	{
		/*theAddress = taddr;
		theName = tnme;
		numTimeConsulted = num;*/
		cout << theName << theAddress << numTimeConsulted << endl;
	}
	~AdBEntry();

private:
	string theName;
	string theAddress;
	int numTimeConsulted;

};

void main()
{
	AdBEntry abe1;
	return ;
}
#endif

#if 0
#include "iostream"
#include "string"

using namespace  std;
struct myStruct{
	int a;
	string str;
};
class CTextBlock{
public:
	/*CTextBlock ctb0; 会发生2个默认构造函数冲突的问题，去掉下面的new，就是没有默认参数后就不会发生了*/
	//CTextBlock()  { cout << endl << "00 constrator\n"; }  
	//CTextBlock(char *pt = new char[capacity]) :pText(pt) { cout << endl << "11 constrator\n"; }

	CTextBlock() :pText(), str()  { cout << endl << "00 constrator\n"; }
	CTextBlock(char *pt) :pText(pt) { cout << endl << "11 constrator\n"; }
	//CTextBlock(char *pt,string s) :pText(pt),str(s) { cout << endl << "11 constrator\n"; }
	CTextBlock(char *pt, string s, struct myStruct mstr) { pText = pt; str = s; mss = mstr; cout << endl << "assign \n"; }

	char & operator[](size_t position) const //const 返回如果是const，后面就不能修改
	{
		return pText[position];
	}
	void print()const {
		cout << capacity << endl;
		cout << pText << endl;
	}
private:
	enum { capacity = 20 };  //capacity就是一个常量了，，是属于类的专属常量，与#define不同 efc1
	char * pText;
	string str;
	struct myStruct mss;
};

void main()
{
				//struct myStruct ms(1, "sfsd")//错误，无构造函数，，，
	struct myStruct ms;
	ms.a = 1;
	ms.str = "sfsd";
	CTextBlock cead("ab", "adfad",ms);
	//CTextBlock ctb0;
	//const CTextBlock ctb1("abcdef");
	//ctb1.print();
	//char *ch = &ctb1[0];  //操作符返回的是引用，导致最终这个还是常量对象本身的元素的bit，
	//cout << *ch << endl;
	//*ch = 'f';			//但是，并不能修改，这个地方会报错，，，，运行失败
	//ctb1.print(); 

}
#endif