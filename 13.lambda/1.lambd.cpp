
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;
//仿函数
class _fun{
public:
	explicit _fun(int b) :m_a(b){};
	bool operator()(int c){
		return c > m_a;
	}
private:
	int m_a;
};
class _fun1{
public:
	_fun1(int i = 1, int j = 2) : a(i),b(j){};
	int operator()() const {return a + b;}
private:
	int a;
	int b;
};
bool compare(const vector<int>& vec, const vector<int>& vec2){//sort对 二维vector排序
	if (vec[0] > vec2[0])
		return true;
	else if (vec[0] == vec2[0])
		return vec[1] > vec2[1];
	else
		return false;
}
inline void larger(int i){ if (i > 10) cout << "bigger than 10 = " << i << endl; };

//[] () [mutable] ->type { ---;};
int main(){
	vector<vector<int>> vvec{ { 1, 2 }, { 1, 0 }, { 1, 5 }, { 1, -1 }, { 2, 3 }, { 0, 5 }, { 3, 2 } };
	//sort(vvec.begin(), vvec.end(), [](vector<int> &vec, vector<int>& vec2){return vec[0] > vec2[0]; });
	sort(vvec.begin(), vvec.end(), compare);
	for (auto it : vvec)
	{
		for (auto it2 : it)
		{
			cout << " " << it2;
		}
		cout << endl;
	}

	cout << "最简单的lambda= []{};";
	[]{};
	int a = 1, b = 2;
	auto fun1 = [=] {return a + b; };  //编译器推断,,
	/*class _fun1{
	public:
		_fun1(int i = 1, int j = 2) :a(i), b(j){};
		int operator()() const {
			return a + b;
		}
	private:
		int a;
		int b;
	};*/
	cout << "[=] {return a+b} =" << fun1() << endl;

	cout << "\n";
	auto fun2 = [&](int c) {b = a + c; };  //
	fun2(100);
	cout << "b=" << b << endl;
	
	cout << "\n";
	auto fun3 = [=, &b] (int c)->int {return a + b; };  //,
	cout << "fun3= " << fun3(1000) << endl;

	//[=, a]{};
	//[&, &b]{};
	//[this]{};
	cout << "\n";
	_fun f(3);
	cout << f(5) << endl;

	int cd = 1;
	//auto fun4 = [=]() {cd = 2; };
	auto fun4 = [=]() mutable {cd = 2; };


	//lambda与stl。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
	cout << "\nstl----lambda..\n";
	vector<int> vec{ 1, 3, 3, 5, 26, 26, 2, 623, 2, 36, 2, 6, 23 };
	for_each(vec.begin(), vec.end(), larger);
	cout << "\n使用lambda搞定...[=](int i){} \n";
	for_each(vec.begin(), vec.end(), [](int i){
		if (i > 10) cout << "lambda..>10 = " << i << endl; });
	//也可以使用仿函数.....

	return 0;
}


