#if 0
#include "iostream"
#include "string"
using namespace std;
//#define  N 10
int main()
{
	
	const unsigned short N = 10;
	int num[N];

	//std::cout << "input 10 data:\n";
	int i;
	cin.ignore();//也会忽略第一个遇到的a，如果是被a分割的，，
	cin >> i;
	while (cin.fail()){ //http://blog.sina.com.cn/s/blog_75b0e2ad01016wap.html
		cout <<" fial" << endl;
		cin.clear();
		cin.ignore(5, 'a');
		cin >> i;
		cout << i;

	};
	cout << i << endl;
	cin >> i;
	cout << i << endl;
	//cin.ignore(2);
	char a;
	cin >> a;
	cout << "a ---" << a << endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "input NO." << i + 1 << "data\n";
		while (!(std::cin >> num[i])) //输入到numi中，如果输入的不是数字，就会出错，就要重新输入
		{
			std::cout << "reinput ,input error!\n";
			//cin >> a;
			std::cin.clear();   //这个是清楚状态
			std::cin.ignore(2, '\n'); //忽视掉
		}
	}
	int total = 0;
	for (int j = 0; j < 10; j++)
	{
		total += num[j];

	}

	std::cout << "sum is" << total << std::endl;
	std::cout << "average is" << (float)total / 10 << std::endl;
	return 0;






}
#endif

#if 0
#include<iostream>  
using   namespace   std;

void main()
{
	char   str1[30], str2[30], str3[30];
	cout << "请输入你的姓名：";
	cin >> str1;
	cout << str1 << endl;
	cout << "请输入你的住址：";
	cin.ignore();
	cin.getline(str2, 30, 'a');
	cout << str2 << endl;
	cout << "请输入你的籍贯：";
	//cin.ignore();
	cin.getline(str3, 30);
	cout << str3;
}
#endif