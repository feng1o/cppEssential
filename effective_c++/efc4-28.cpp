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
	/*CTextBlock ctb0; �ᷢ��2��Ĭ�Ϲ��캯����ͻ�����⣬ȥ�������new������û��Ĭ�ϲ�����Ͳ��ᷢ����*/
	//CTextBlock()  { cout << endl << "00 constrator\n"; }  
	//CTextBlock(char *pt = new char[capacity]) :pText(pt) { cout << endl << "11 constrator\n"; }

	CTextBlock() :pText(), str()  { cout << endl << "00 constrator\n"; }
	CTextBlock(char *pt) :pText(pt) { cout << endl << "11 constrator\n"; }
	//CTextBlock(char *pt,string s) :pText(pt),str(s) { cout << endl << "11 constrator\n"; }
	CTextBlock(char *pt, string s, struct myStruct mstr) { pText = pt; str = s; mss = mstr; cout << endl << "assign \n"; }

	char & operator[](size_t position) const //const ���������const������Ͳ����޸�
	{
		return pText[position];
	}
	void print()const {
		cout << capacity << endl;
		cout << pText << endl;
	}
private:
	enum { capacity = 20 };  //capacity����һ�������ˣ������������ר����������#define��ͬ efc1
	char * pText;
	string str;
	struct myStruct mss;
};

void main()
{
				//struct myStruct ms(1, "sfsd")//�����޹��캯��������
	struct myStruct ms;
	ms.a = 1;
	ms.str = "sfsd";
	CTextBlock cead("ab", "adfad",ms);
	//CTextBlock ctb0;
	//const CTextBlock ctb1("abcdef");
	//ctb1.print();
	//char *ch = &ctb1[0];  //���������ص������ã���������������ǳ����������Ԫ�ص�bit��
	//cout << *ch << endl;
	//*ch = 'f';			//���ǣ��������޸ģ�����ط��ᱨ������������ʧ��
	//ctb1.print(); 

}
#endif