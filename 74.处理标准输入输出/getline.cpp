#if 0
#include "iostream"
#include "string"
using namespace std;

int main(){
	string str;
	getline(cin, str, '#');
	cout << "#·Ö¸î" << str << endl;
	while (getline(cin, str)){
		cout << str << endl;
	}
	char ch;
	cin >> ch;
	cout << endl << ch << endl;
	return 0;
}
#endif