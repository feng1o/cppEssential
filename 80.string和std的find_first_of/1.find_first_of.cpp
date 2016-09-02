
//1.find_first_of均不是找一个字符串的，是找一个，，，，只是string的是整队字符或者串，std对迭代器
	//find:
	//size_t find(const string& str, size_t pos = 0) const noexcept;
	//size_t find(const char* s, size_t pos = 0) const;	
	//size_t find(const char* s, size_t pos, size_type n) const;
	//size_t find(char c, size_t pos = 0) const noexcept;	

//2.返回值问题，string::npos，，，std的返回end()没找到；注意判定
	//std::find只能找一个 value
	//template <class InputIterator, class T>
		//InputIterator find(InputIterator first, InputIterator last, const T& val);
//3.参数
//4.substr(0, npos)默认，，不包含最后一个
	//string substr(size_t pos = 0, size_t len = npos) cons
//5."\nerase擦除。。。。。 \n";  //erase是擦除从n1开始，n2长个字符的
	//string& erase(size_t pos = 0, size_t len = npos);
	//iterator erase(const_iterator p);
	//iterator erase(const_iterator first, const_iterator last);
//6. std::search是找一个串的....
	//最后一个即使是数组，也要超过一个...
#include "iostream"
#include "string"
#include "functional"
#include "numeric"
#include "algorithm"
#include "vector"
using namespace std;

void string_find_first_of(){
	string  str = "abcbb,-;bbf";
	size_t  pos = str.find_first_of("bb", 0);//1. 不是找一个串，是任何一个，，，find_first_not_of也是一样的
	if (pos != string::npos)
	{
		cout << "string find pos = " << pos << ">>" << str.substr(0, pos)<< endl << endl; //substr(pos1, pos2)不会包含pos2
	}
	else
		cout << "connot find....\n\n";

	std::size_t found = str.find_first_of("aeiou"); // 2. find_first_of('c')也是ok
	while (found != std::string::npos)
	{
		str[found] = '*';
		found = str.find_first_of("aei-u", found + 1);
	}

	cout << str << '\n' <<endl;
	
	cout << "\nfind(string/char*,pos)找字符串，不在是一个.....\n";
	auto fpos = str.find("bb");
	if (fpos != string::npos){
		cout << "find pos ==" << fpos << "  element =" << str[fpos] << endl;
	}
}
void std_find_first_of(){
	string  str = "abcbb,-;bbf";
	string  substr = "eeeeeekad";//不是找一个串，是任何一个，
	auto  iter = find_first_of(str.begin(), str.end(), substr.begin(), substr.end());
	//auto  iter = find_first_of(str.begin(), str.end(), 'b', 1 );
	if (iter != str.end())
	{
		cout << "string find pos = " << *iter << endl << endl;
	}
	else
		cout << "connot find....\n\n";


	char a[] = ",";
	auto  iter2 = find_first_of(str.begin(), str.end(), a, a + 1);  //指针仍然是可以作为迭代器的。。。
	char *a = "abcdef";
	//auto iterxxx = find_first_of(a, a + 3, 'a');
	if (iter2 != str.end())
	{
		cout << "string find pos = " << *iter2 << endl << endl;
	}
	else
		cout << "connot find....\n\n";
	cout << "\nstd：：find只能找一个值，不能找一个串，，可使用search。。。。\n";
	cout << "find==" << *find(str.begin(), str.end(), 'c') << endl;
}

bool mypredicate(int i, int j) {
	return (i == j);
}
void std_search(){
	std::vector<int> haystack;
	for (int i = 1; i < 10; i++) haystack.push_back(i * 10);
	int needle1[] = { 40, 50, 60, 70 };
	std::vector<int>::iterator it;
	cout << "\nsearch找一个串，，，std里面的find不能\n";
	it = std::search(haystack.begin(), haystack.end(), needle1, needle1 + 4);//最后一个即使是数组，也要超过一个...

	if (it != haystack.end())
		std::cout << "needle1 found at position " << (it - haystack.begin()) << '\n';
	else
		std::cout << "needle1 not found\n";

	int needle2[] = { 20, 30, 50 };
	it = std::search(haystack.begin(), haystack.end(), needle2, needle2 + 3, mypredicate);

	if (it != haystack.end())
		std::cout << "needle2 found at position " << (it - haystack.begin()) << '\n';
	else
		std::cout << "needle2 not found\n";
	cout << endl;

}
// sting截断问题
void string_substr(){
	cout << "string 截断，，利用\\0只能对char*，不能是string，她未必以\\0结束" << endl;
	string str = "abc,def,ghi";
	str[3] = '\0';
	string substr(str.substr()); //并没有截断，还是一样的 substr(0, npos)默认，，不包含最后一个
	cout << "sub.str=" << substr << '\t' << "str =" << str ;
	cout << "            截断失败.....\n";

	char* strch = const_cast<char*>(str.c_str());
	cout << "strch  =" << strch << '\t' << "str =" << str << "...截断成功......\n\n";

	string substr2 = str.substr(4, 5);  //4后面开始截取5个
	cout << "str.substr(4,7) =" << substr2 << endl;
	string substr3 = str.substr(4);
	cout << "str.substr(4) =" << substr3 << endl;

	cout << "\nerase擦除。。。。。 \n";  //erase是擦除从n1开始，n2长个字符的
	cout << "str.erase(positin, len)===" << str.erase(3, 8) << endl;
	str = "abc,def,ghi";
	cout << "str.erase(iter.begin(), end())" << *str.erase(str.begin() + 3, str.begin() + 8) << endl;//不会丢失地址
	//cout << "str.erase(iter.begin(), end())...===" << *str.erase(str.begin() + 3, str.end() - 3) << endl;
	cout << "\nstr.erase(str.begin() + 3, str.end() - 3)===" << str << endl;
}

int main(){
	cout << "test....find_first of....\n";
	string_find_first_of();
	std_find_first_of();
	string_substr();
	std_search();
	return 0;
}