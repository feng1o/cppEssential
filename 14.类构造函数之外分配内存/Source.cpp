#include "test.h"
/*�˷������ڹ��캯����������ڴ�ռ���ʲô�����أ���������
tip��
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