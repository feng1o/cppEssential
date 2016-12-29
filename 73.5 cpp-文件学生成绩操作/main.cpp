#include "handler.h"

using namespace std;

int main(){
	cout << "	Recreat file: student.txt and course.txt (y/n)£º";
	char c = 'n';
	cin >> c;
	if (c == 'y')
	{
		remove("student.txt");
		remove("course.txt");
		fstream fs;
		fs.open("student.txt", ios::app | ios::binary);
		fs.close();
		fs.open("course.txt", ios::app | ios::binary);
		fs.close();
	}
	cout << endl;

	string menu = "\t\t****************MAIN MENU****************\n\
		\t\t	0.course info\n\
		\t\t	1.student info\n\
		\t\t	2.search scroe\n\
		\t\t	3.statistical score\n\
		\t\t	4.go out\n\
		\t\t****************MAIN MENU****************\n\n";
	Handler handle("student.txt", "course.txt");
	while (1){
		cout << menu << endl;
		int n = 4;
		cin >> n;
		switch (n){
		case 0:{
			handle.courseInfo();
			break;
		}
		case 1:{
			handle.stuInfo();
			break;
		}
		case 2:{
			handle.search();
			break;
		}
		case 3:{
			handle.statistic();
			break;
		}
		case 4:{
			return 0;
		}
		default:	{
			cout << "Input error...." << endl;
		}
		}

	}
	return 0;
}
