#if 0
#include "iostream"
#include "string"

using namespace  std;
class CTextBlock{
public:
	/*CTextBlock ctb0; �ᷢ��2��Ĭ�Ϲ��캯����ͻ�����⣬ȥ�������new������û��Ĭ�ϲ�����Ͳ��ᷢ����*/
	//CTextBlock()  { cout << endl << "00 constrator\n"; }  
	//CTextBlock(char *pt = new char[capacity]) :pText(pt) { cout << endl << "11 constrator\n"; }
	
	CTextBlock()  { cout << endl << "00 constrator\n"; }
	CTextBlock(char *pt ) :pText(pt) { cout << endl << "11 constrator\n"; }
	
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
};

void main()
{
	CTextBlock ctb0;
	const CTextBlock ctb1("abcdef");
	ctb1.print();
    char *ch = &ctb1[0];  //���������ص������ã���������������ǳ����������Ԫ�ص�bit��
	cout << *ch << endl;
	//*ch = 'f';			//���ǣ��������޸ģ�����ط��ᱨ������������ʧ��
	//ctb1.print(); 

}
#endif