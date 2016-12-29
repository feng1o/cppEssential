#include "test.h"
/*此方法和在构造函数里面分配内存空间有什么区别呢？？？？？
tip：
1.为什么 03.1中就不能这样，必须引用呢？？？
			因为一开始在析构函数里面没free掉堆内存，所以对了，，加了free就错了，，，
			
			故，必须用深拷贝*/

void initTest(CTest test){  //如果没有深拷贝，，必须使用引用
	test.init();  //必须使用深拷贝
};
int main(){
	CTest test;
	test.initMemory(10);


	initTest(test);
	for (int i = 0; i < 10; ++i)
	{
		test.setValue(i, "aaa");
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << test.getValue(i) << endl;
	}
	return 0;
}