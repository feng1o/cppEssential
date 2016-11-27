#if 0
#include<iostream>
#include<string>
#include "algorithm"
#include "numeric"

using namespace std;
typedef struct position{
	int x;
	int y;
	position() :x(0), y(0){};
}position;

int main(){
	position  pos;
	string str;
	while (getline(cin, str)){
		while (!str.empty()){

			string fstr = ";";
					//auto iter = find_first_of(str.begin(), str.end(), ';');
			auto iter = find_first_of(str.begin(), str.end(), fstr.begin(), fstr.begin()+1);  //必须使用迭代器，不可以使用字符串指定问题，string的可以
			if (iter!=str.end())  //判定返回值
				cout << *iter << endl << endl;

			auto it = str.find_first_of(';', 0);
			if (it == string::npos) //-1
				break;
			cout << it << endl;

			str[it] = '\0';  //string这个居然不会结束...>han....char*会。。。。
			string substr(str.substr()); 
			cout << "substr : " << substr << endl;  //不会截断，，string不一定是\0结束的....

			char* chr = const_cast<char*> (str.c_str());
			cout << "\nchr...." << chr << endl;// 会被截断.....

			str.erase(0, it+1); //切记不会包含最后一个
			cout << "str.." << str << endl;
		}
	}
	return 0;
}
#endif