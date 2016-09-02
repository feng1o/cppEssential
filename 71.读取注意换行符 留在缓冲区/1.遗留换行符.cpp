
#include "iostream"
#include "string"

using namespace std;

int main(){
	string  str;
	int n;
	while (cin >> n){
		//cin.ignore(6, '\n');
		 getchar();
		getline(cin, str);  //会为空，，，拿到\n丢球，，，输出孔
		cout << "getline=" << str << endl;
		while (n--)
		{
			cin >> str;
			cout << "read =" << str << endl;
		}
	}
	return 0;
}