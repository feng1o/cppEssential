#include "test.h"
/*�˷������ڹ��캯����������ڴ�ռ���ʲô�����أ���������
tip��
1.Ϊʲô 03.1�оͲ������������������أ�����
			��Ϊһ��ʼ��������������ûfree�����ڴ棬���Զ��ˣ�������free�ʹ��ˣ�����
			
			�ʣ����������*/

void initTest(CTest test){  //���û�������������ʹ������
	test.init();  //����ʹ�����
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