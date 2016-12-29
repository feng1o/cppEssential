/*问题：
1.类如何写入文件？比如有方法，有string的，就必须序列化她。。。。
2.如果想写入呢，，简化为结构提
3. xml， json？怎么用？
*/


#include "handler.h"

using namespace std;

int main(){
	string menu = "\t\t****************MAIN MENU****************\n"
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