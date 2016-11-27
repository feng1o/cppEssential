#include "iostream"
#include "iomanip"
#include "numeric"
#include "algorithm"
#include "functional"
#include "vector"
using namespace std;


class Solution {
public:
	void Insert(int num)
	{
		if (((max.size() + min.size()) & 1) == 0){
			if (max.size() > 0 && max[0] > num){
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>());

				num = max[0];

				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>());
		}
		else{
			if (min.size() > 0 && min[0] < num){
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());

				num = min[0];

				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		}
	}
	double GetMedian()
	{
		for (auto it : max)
			cout << "max :" << it << endl;
		for (auto it2 : min)
			cout << it2 << endl;
		/*int size = min.size() + max.size();
		if (size == 0)
		return 0.0;
		if (size % 2 == 1){
		return min[0];
		}
		else
		return (min[0] + max[0]) / static_cast<double> (2.0);*/
		return 0.0;
	}
private:
	vector<int> max;
	vector<int> min;
};


int main(){
	less<int>  less;
	cout << std::boolalpha<< less(1, 2) << endl;
	vector<int> ivec{ 1, 2, 3, 4, 5, 6 };
	make_heap(ivec.begin(), ivec.end(), greater<int>());  //Ð¡¸ù¶Ñ£¿£¿why

	for (auto it : ivec)
	{
		cout << it << endl;
	}
	Solution sol;
	for (;;)
	{
		int num;
		cin >> num;
		sol.Insert(num);
		cout << sol.GetMedian() << endl;
	}
	return 0;
}