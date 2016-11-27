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
void deal(position& pos, string substr);

int main(){
	position  pos;
	string str;
	while (getline(cin, str)){
		cout << "..." << str.length() << endl;
		while (!str.empty()){
			//string fstr = ";";
			//		//auto iter = find_first_of(str.begin(), str.end(), ';');
			//auto iter = find_first_of(str.begin(), str.end(), fstr.begin(), fstr.begin()+1);
			//if (iter!=str.end())
			//	cout << *iter << endl << endl;
			auto it = str.find_first_of(';',0);
			if (it == string::npos)
				break;
			cout << it << endl;

			str[it] = '\0';
			string substr(str.substr(0, it)); //tip
			cout << "substr : " << substr << endl;

			str.erase(0, it+1);
			cout << "str.." << str << endl;
			deal(pos, substr);
			cout << "\n...size...." << str.size() << endl;
		}
		cout << "(" << pos.x << " , " << pos.y << ")" << endl;
		//return 0;
	}

}

void deal(position& pos, string substr){
	const size_t  len = substr.size();
	cout << "len....ok:>>>" << len << endl << endl;
	int num = 0;
	for (int i = 1; i < len; ++i){
		if (!isdigit(substr[i]))
			return;
		num = num * 10 + (substr[i] - '0');
	}
	if (substr[0] =='A')
	{
		pos.x -= num;
	}
	else if (substr[0] == 'S')
	{
		pos.y -= num;
	}
	else if (substr[0] == 'W')
	{
		pos.y += num;
	}
	else if (substr[0] == 'D')
	{
		pos.x += num;
	}
	else
		return;
	cout << "(" << pos.x << " , " << pos.y << ")" << endl;
}
#endif