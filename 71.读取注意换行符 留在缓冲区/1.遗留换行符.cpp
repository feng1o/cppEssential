
#include "iostream"
#include "string"

using namespace std;

int main(){
	string  str;
	int n;
	while (cin >> n){
		//cin.ignore(6, '\n');
		 getchar();
		getline(cin, str);  //��Ϊ�գ������õ�\n���򣬣��������
		cout << "getline=" << str << endl;
		while (n--)
		{
			cin >> str;
			cout << "read =" << str << endl;
		}
	}
	return 0;
}