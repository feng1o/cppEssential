/*
�޸��ļ��������ݣ�ʹ��c++��seekg��seekpΪʲôʧ���ˣ�������ô���ġ�
��ʱ��c��*/


#include "handler.h"

using namespace std;

int main(){
	string menu = "\t\t****************MAIN MENU****************\n"
		"\t\t	0.course info\n"
		"\t\t	1.student info\n"
		"\t\t	2.search scroe\n"
		"\t\t	3.statistical score\n"
		"\t\t	4.go out\n"
		"\t\t****************MAIN MENU****************\n\n";
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