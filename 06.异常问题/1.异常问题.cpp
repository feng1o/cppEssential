#if 0
/*跑出异常和函数调用有些不同，主要异常后权限不会返回到抛出者
  即使局部静态对象，也会发生复制行为，如果 throw ew，而不是throw；
  不要跑出局部临时变量的指针 throw &i   不要跑出new堆上的指针，不知道何时delete......
  铺货用引用 ；；；不要使用常量引用捕获，临时对象可以传递一个异常非常量引用的，，但是在函数中不可。。。可减少一次复制，如果不是引用会2次，
  throw直接就ok  减少一次复制，，而且能抛出原对象，不是复制的副本，也就是不会发生因静态类型和动态类型问题，，
  catch不是最佳匹配
  exception的拷贝构造函数是依据静态类型来拷贝的。。。因此，如果throw w，就会剖出静态对象的类型了。。。
*/

#include "iostream"
#include "exception"

using namespace std;

void fun_1(){
	try{
		throw 2;
	}
	catch (const int i){  //m没事勇士引用，，，这个地方2次复制
		cout << "catch " << i << endl;
		throw;
	}
	catch (const int &i){
		throw;//抛出原对象，，，const的了，，
	}
}

void fun_2(){
	try{
		throw 2;
	}
	catch (int i){
		cout << "catch " << i << endl;
		throw;
	}
}

void fun_3(){
	try
	{
		throw  range_error("range error....\n\n");
	}
	catch (exception* e)
	{
		cout << e->what() << endl;
		cout << "excepiton...\n\n";
	}
	catch (runtime_error& e)
	{
		cout << "runtime error...." << e.what() << endl;
	}
}

int main(){
	try{
		fun_1();
	}
	catch (...){
		cout << "catch ...main...\n";
	};

	fun_3();

	fun_2();  //未捕获异常 程序错误终止
	cout << "ok???";
	return 0;
}
#endif