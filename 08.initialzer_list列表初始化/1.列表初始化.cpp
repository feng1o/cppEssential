#include "iostream"
#include "initializer_list"
#include "string"
#include "utility"
using namespace std;

void fun(initializer_list<pair<string, int>> initp){
	for (auto &it : initp)
	{
		cout << "pair..fisrt:" << it.first << "\nsecond.." << it.second << endl;
	}
}


int main(){
	int a[]{1, 2, 3, 5};
	fun({ { "liu", 2 }, { "feng", 3 } });
	return 0;
}