#include "test.h"
/*此方法和在构造函数里面分配内存空间有什么区别呢？？？？？
tip：
1.*/
int main(){

	CTest test;
	test.initMemory(10);
	for (int i = 0; i < 10; ++i)
	{
		test.setValue(i, i);
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << test.getValue(i) << endl;
	}
	return 0;
}