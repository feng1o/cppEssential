#include<iostream>
#include<string>
using namespace std;

int main(){
	int n;
	while (cin >> n) {
		int sum = 1;
		int increase = 1;
		int index = 1;
		if (n == 1){
			cout << sum << endl;
			continue;
		}
		for (int i = 2; i <= n; ++i){
			if (!increase){
				sum -= 1;
				increase = ++index;
			}
			else{
				--increase;;
				sum++;;
			}
		}
		cout << sum << endl;
	}
}