#if 0
// 17.错误记录.cpp : Defines the entry point for the console application.
//
#define  _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "string"
#include "unordered_map"
#include "cstdlib"
#include "algorithm"

using namespace std;

typedef struct strRecord{
	string  name;
	int     line;
	int     num;
} err;

int main()
{
	unordered_map<string, int> map;
	string str;
	int line;
	while (cin >> str >> line){
		int size = static_cast<int> (str.size());
		cout << size << endl;
		int pos = str.find_last_of('\\');
		string name = str.substr(pos + 1);
		cout << name << endl;
		cout << pos << endl;
		char* ch = new char[100];
		_itoa(line, ch, 10);
		name = name + ",";  //chaifen
		name = name + ch;
		delete[] ch;
		cout << "name..." << name << endl;
		if (map.count(name) == 0)
		{
			map.insert({ name, 1 });
		}
		else
			++map[name];
		//for (auto it :map)  //返回是一个pair
		//{
		//	cout << it.first <<"...." << it.second << endl;
		//}
	}
	int k = 0;
	for (auto it : map)
	{
		++k;
		if (k == 9)
			break;
		string str = it.first;
		string index = ",";
		auto iter = find_first_of(str.begin(), str.end(), index.begin(), index.begin() + 1);
		string substr(iter+1, str.end());  //+1;
		str.erase(iter, str.end());
		if (str.size()<=16)
		{
			cout << str << " ";
		}
		else{
			//string  cstr = str.substr(str.begin()-16, 16);
			string cstr(str.end() - 16, str.end());
			cout << cstr << " ";
		}
	//	cout << "erars-str=" << str << endl;
	//  cout << "substr..." << substr << endl;
		int line = atoi(substr.c_str());
		//cout << "line" <<line << endl;
		cout << line << " ";
		int num = it.second;
		cout << num << endl;
	}
	return 0;
}

#endif