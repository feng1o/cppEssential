
#if 01
/*
*
* 	Fax: (201) 236-3290
*/

#include "iostream"
#include "string"
using namespace std;

class Base
{
public:
	Base() :b(100)
	{
		//m_cStr = "xx";//const��Ա���ܸ�ֵ���б��ʼ��������Ĭ�ϳ�ʼ��
		cout << "constrator \n";
	}
	
	void fun(Base &cb)
	{
		cout << endl;
		cout << "no static fun ! \n";
		cout << "�ɷ��ʷ�static��Աb=" << b << endl;
		cout << "�ɷ���static��Ա����a=" << cb.a << endl;
	}
	static int  sfun(Base &cb) //��̬��Ա������������Ϊconst,��̬��Ա��������ʹ��thisָ��
	{
		cout << endl;
		cout << "static sfun  \n";
		cout << "�ɷ���static��Ա����a=" << a << endl;
		//cout << "���ɷ��ʷ�static��Ա����b=" <<Base:: b �� //ֻ��ͨ�����ݶ���Ȼ��ͨ������xx��xx.b�϶��ǿ��Ե� ��̬��Ա��������ʹ��thisָ��
		cout << "ֻ��ͨ��������ʷ�static��Ա����cb.b=" << cb.b << endl;
		return true;
	}

	const int cFun(string m_cStr,const Base cbas) const {  //����ط��Ĵ��ݲ����Ǵ��ݸ���������ĳ�Ա,m_str�Ǳ�
		cout << endl;
		cout << "const��������const��Ա����cstr=" << m_cStr << endl;
		cout << "const�������const��Ա����cstr="<<cbas.m_cStr << endl;
		cout << "const���������const��Ա����cstr=" << cbas.b << endl;
		//cbas.b = 2;            //const��Ա���������޸ķ�mutable����ͨ��Ա����
		//return 1; //����������ok�ģ����������ָ�����þͲ��У�������ok�����ǣ�1��һ���ֲ�������������������ʧЧ��
		int i = 2;
		//return i;
		return cbas.b; 
	}
	~Base() = default;

private:
	//static int  a=1;//������һ�����������Ƕ��壬������funִ�е�"t.a = 3;"ʱ�������ٰ�a����Ϊһ���ⲿ���ţ������������δ������ű��С�a���ȱ���ֵΪ0
	static int a; //ֻ��һ������
	int b = 2;
	const string m_cStr = "const string";
};




int Base::a = 1; //ʹ��ǰ���壬����һ���ⲿ�������ҵ����ﶨ������ʹ�ã���
void main()
{

	Base ba; //���๹��
	ba.fun(ba);
	ba.sfun(ba);
	Base bb;
	bb = ba;
	
	const Base cba; //const�������治�ܵ��ö��������const��Ա
	//cba.fun(cba); //const�������治�ܵ��ö��������const��Ա
	//cba.sfun(cba); //const�������治�ܵ��ö��������const��Ա
const	int ra = cba.cFun("adfb",cba);
	cout << endl << ra << endl;

	


#if 0
	auto a = 12.0F;
	std::cout << sizeof(a) << std::endl;
	int i = 20;
	decltype(i) bi1;
	decltype((i)) bi2 = bi1; //������ ��������int��
#endif

#if 0
	std::cout << std::endl;
	int i = 0;
	int a = i++; //a=0;
	cout << a << endl;
	int b = ++a;//b=1  a=1???  �˴�����b=(a=a+1);
	cout << "x" << a << b << endl;
	int  c = a + b; //c =2;
	cout << "x2:" << a << b << c << endl;//1 1 2
	int d;
	d = (a ? b : c); cout << "d: " << d << endl; //�����1����������
#endif

}
#endif
