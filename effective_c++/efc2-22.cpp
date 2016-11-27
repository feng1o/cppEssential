#if 0
#include "iostream"
#include "string"

using namespace  std;
class CTextBlock{
public:
	/*CTextBlock ctb0; 会发生2个默认构造函数冲突的问题，去掉下面的new，就是没有默认参数后就不会发生了*/
	//CTextBlock()  { cout << endl << "00 constrator\n"; }  
	//CTextBlock(char *pt = new char[capacity]) :pText(pt) { cout << endl << "11 constrator\n"; }
	
	CTextBlock()  { cout << endl << "00 constrator\n"; }
	CTextBlock(char *pt ) :pText(pt) { cout << endl << "11 constrator\n"; }
	
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
};

void main()
{
	CTextBlock ctb0;
	const CTextBlock ctb1("abcdef");
	ctb1.print();
    char *ch = &ctb1[0];  //操作符返回的是引用，导致最终这个还是常量对象本身的元素的bit，
	cout << *ch << endl;
	//*ch = 'f';			//但是，并不能修改，这个地方会报错，，，，运行失败
	//ctb1.print(); 

}
#endif