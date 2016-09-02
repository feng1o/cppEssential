
#include "iostream"
#include "algorithm"
#include "numeric"
#include "vector"
#include "iterator"


using namespace std;
template<typename T>

class increas{
public:
	void operator()(T& it){
		it += 1;
	}
};
int main(){
	vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto &it : ivec)
	{
		cout << it << endl;
	}
	for_each(ivec.begin(), ivec.end(), increas<int>());
	ivec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << "accumulate : " << accumulate(ivec.begin(), ivec.end(), 1) << endl;
	cout << "accumulate : " << accumulate(ivec.begin(), ivec.end(), 0) << endl;

	//ostream_iterator<int> oit{1, 2, 3, 4, 5, 6, 7, 8, 9}; //iterator
	ostream_iterator<int> oit(cout, " £º "); //iterator

	adjacent_difference(ivec.begin(), ivec.end(), oit);
	cout << endl;
	adjacent_difference(ivec.begin(), ivec.end(), oit, plus<int>());

	return 0;
}