#if 0
//xsjswt@SnowWind:~$ cat test.c
#include "stdio.h"

int main(){
	int test1 = 1;
	const int test2 = 2;
	int *p;
	printf("test1=%d &test1=%p\n", test1, &test1);
	//printf("test2=%d &test2=%p\n", test2, &test2); 
	//ȥ�����test2���������Ͳ�����ջ�Ϸ���test2;p++֮��Ҫôָ��cookie(��release���룬��û��cookies�Ͳ��ᱨ��release��ʱ�򲻼��cookie��; Ҫôָ�򷵻ص�ַ

	/*const ����Ǽ�ֵ��ͬʱû�ж��������������,��ô�ڴ��в������������
	 *�õ�ʱ���ֱ�Ӹ�Ŀ��ط���ֵ����ѹջ,��������£�const�൱��define��һ������
	 *����Ǹ��Ӽܹ��壬���߶Լ�ֵ����ȡ��ַ����
	 *��һ�����������������ڴ�,������ȫ�ֻ���ջ
	 */
	p = &test1;
	*(p--) = 3;
	*p = 4;
	printf("test1=%d &test1=%p\n", test1, &test1);
	printf("test2=%d &test2=%p\n", test2, &test2);
	return 0;
}
//xsjswt@SnowWind:~$ gcc test.c
//xsjswt@SnowWind : ~$ . / a.out
//test1 = 1 & test1 = 0x7ffd87d5a570
//test2 = 2 & test2 = 0x7ffd87d5a574
//test1 = 3 & test1 = 0x7ffd87d5a570
//test2 = 4 & test2 = 0x7ffd87d5a574
#endif
#if 0
#include "iostream"
#include "string"
using namespace std;

//const int ceF(){ //����û��ϵ����const����Ĭ�Ͼ���һ����ʼ������
const int& ceF(){
	int a = 1211232;
	return a; //���صķ����û���ָ�룬��ô�͵���������һ�������ĸ�������const int ���󣨶�����ʼ��������
}

//int& ef() //const�����õ�int��������const�����int
int eF(){
	const int a = 1211232;
	return a;				 //������ok�ģ��������û���ָ���Ȼerror
}


void main()
{
	char* str;
	str= "aaaa";
	//str[0] = 'b'; //�޸���error�ģ����ܸı䣬������������������ʱ��error
	cout << "char* str���������޸�ֻ�ܶ� str=" <<str << endl;
	cout << "................................\n";

	string  str2 = "aaaa";
	str2[0] = 'b'; //�ı��ˣ���������������
	cout << "string��str�ɱ�str2=" << str2 << endl;
	cout << "................................\n";


	int inum = 2;
	const int cinum = 3;
	const int cinum2 = inum;  //�����������Ϊ�ȼ��ڶ�const int��ʼ������
	//cinum = inum; //����������ܣ�const�ı��������ٴα���ֵ����
	inum = cinum;
	//cinum = cinum2;
	cout << "................................\n";

	const int rac = ceF();
	const int *i;//ָ�벻��const�ģ����Կ��Ը�
	//*i = rac;//���
	i = &rac;//ok
	cout << "const int i���Խ����κη������͵�ֵ����Ϊ��Ĭ�϶�i��ʼ�� rac= " << rac << endl;
	cout << "................................\n";


	const int rac2 = eF(); //��������ʼ����������Ȼ���ص�int�����ǣ�const����ʼ����Ӱ��
	cout << "const int i���Խ����κη������͵�ֵ����Ϊ��Ĭ�϶�i��ʼ�� rac2= " << rac2 << endl;
	cout << "................................\n";

	cout << "const int *i���Բ�����ʼ����������i=" << i << "  *i =" << *i << endl;
	cout << "................................\n";
	
}

#endif