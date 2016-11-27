#if 0
//xsjswt@SnowWind:~$ cat test.c
#include "stdio.h"

int main(){
	int test1 = 1;
	const int test2 = 2;
	int *p;
	printf("test1=%d &test1=%p\n", test1, &test1);
	//printf("test2=%d &test2=%p\n", test2, &test2); 
	//去掉这个test2，编译器就不会在栈上分配test2;p++之后要么指向cookie(用release编译，就没有cookies就不会报错，release的时候不检查cookie）; 要么指向返回地址

	/*const 如果是简单值，同时没有对这个变量做引用,那么内存中不存在这个变量
	 *用的时候会直接给目标地方赋值或者压栈,这种情况下，const相当于define了一个常量
	 *如果是复杂架构体，或者对简单值做了取地址运算
	 *则一定会给这个变量分配内存,无论是全局还是栈
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

//const int ceF(){ //引用没关系，因const这里默认就是一个初始化，，
const int& ceF(){
	int a = 1211232;
	return a; //返回的非引用或者指针，那么就等于是有了一个拷贝的副本，给const int 对象（对他初始化）；；
}

//int& ef() //const的引用到int，不能用const对象给int
int eF(){
	const int a = 1211232;
	return a;				 //返回是ok的，但是引用或者指针必然error
}


void main()
{
	char* str;
	str= "aaaa";
	//str[0] = 'b'; //修改是error的，不能改变，编译器不会差错，，运行时候error
	cout << "char* str常量不可修改只能读 str=" <<str << endl;
	cout << "................................\n";

	string  str2 = "aaaa";
	str2[0] = 'b'; //改变了，，，，，，，，
	cout << "string的str可变str2=" << str2 << endl;
	cout << "................................\n";


	int inum = 2;
	const int cinum = 3;
	const int cinum2 = inum;  //这个可以是因为等价于对const int初始化，，
	//cinum = inum; //错误，这个不能；const的变量不能再次被赋值，，
	inum = cinum;
	//cinum = cinum2;
	cout << "................................\n";

	const int rac = ceF();
	const int *i;//指针不是const的，所以可以改
	//*i = rac;//错的
	i = &rac;//ok
	cout << "const int i可以接收任何返回类型的值，因为是默认对i初始化 rac= " << rac << endl;
	cout << "................................\n";


	const int rac2 = eF(); //（对他初始化）；；虽然返回的int，但是，const被初始化无影响
	cout << "const int i可以接收任何返回类型的值，因为是默认对i初始化 rac2= " << rac2 << endl;
	cout << "................................\n";

	cout << "const int *i可以不被初始化？？？：i=" << i << "  *i =" << *i << endl;
	cout << "................................\n";
	
}

#endif