
#define  _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "string"
#include "sstream"
#include "vector"
#include "algorithm"
#include "stdio.h"
using namespace  std;

int main()
{
	//解决1
	string str;
	vector<string> svec;
	getline(cin, str);
	while (str != "") //空行时退出
	{
		svec.push_back(str);
		getline(cin, str);
	}

	//解决 2
	string str;
	vector<vector<int> > vvec;
	while (cin.peek() != '\n' && getline(cin, str)){                         //peek使用
		stringstream ss;
		vector<int> vec;
		ss.str("");
		ss << str;
		int tmp;
		vector<int>  tvec;
		while (ss >> tmp){
			vec.push_back(tmp);
		}
		vvec.push_back(vec);
		for (auto it : vec)
		{
			cout << "..." << it << endl;
		}
	/*	while (cin >> tmp){
			if (find(tvec.begin(), tvec.end(), tmp) == tvec.end()){
				vec.push_back(tmp);
				tvec.push_back(tmp);
			}
			else {
				tvec.push_back(tmp);
				vvec.push_back(vec);
				vec.clear();
				vec.push_back(tmp);
			}
			
		}
		vvec.push_back(vec);*/
	}
	vector<int> ans;

		for (int j = 0; j < vvec[0].size(); ++j)
		{
			ans.push_back(vvec[0][j]);
		}
		for (int i = 1; i < vvec.size(); ++i)
		{
			if (find(ans.begin(), ans.end(), vvec[i][0]) != ans.end()){
				for (int j = 1; j < vvec[i].size(); ++j)
				{
					ans.push_back(vvec[i][j]);
				}
			}
		}
		for (int i = 0; i < ans.size()-1; ++i)
		{
			cout << ans[i] << " ";
		}
		cout << ans[ans.size() - 1] << endl;
	return 0;
}
