
//1.find_first_of��������һ���ַ����ģ�����һ����������ֻ��string���������ַ����ߴ���std�Ե�����
	//find:
	//size_t find(const string& str, size_t pos = 0) const noexcept;
	//size_t find(const char* s, size_t pos = 0) const;	
	//size_t find(const char* s, size_t pos, size_type n) const;
	//size_t find(char c, size_t pos = 0) const noexcept;	

//2.����ֵ���⣬string::npos������std�ķ���end()û�ҵ���ע���ж�
	//std::findֻ����һ�� value
	//template <class InputIterator, class T>
		//InputIterator find(InputIterator first, InputIterator last, const T& val);
//3.����
//4.substr(0, npos)Ĭ�ϣ������������һ��
	//string substr(size_t pos = 0, size_t len = npos) cons
//5."\nerase�������������� \n";  //erase�ǲ�����n1��ʼ��n2�����ַ���
	//string& erase(size_t pos = 0, size_t len = npos);
	//iterator erase(const_iterator p);
	//iterator erase(const_iterator first, const_iterator last);
//6. std::search����һ������....
	//���һ����ʹ�����飬ҲҪ����һ��...
#include "iostream"
#include "string"
#include "functional"
#include "numeric"
#include "algorithm"
#include "vector"
using namespace std;

void string_find_first_of(){
	string  str = "abcbb,-;bbf";
	size_t  pos = str.find_first_of("bb", 0);//1. ������һ���������κ�һ��������find_first_not_ofҲ��һ����
	if (pos != string::npos)
	{
		cout << "string find pos = " << pos << ">>" << str.substr(0, pos)<< endl << endl; //substr(pos1, pos2)�������pos2
	}
	else
		cout << "connot find....\n\n";

	std::size_t found = str.find_first_of("aeiou"); // 2. find_first_of('c')Ҳ��ok
	while (found != std::string::npos)
	{
		str[found] = '*';
		found = str.find_first_of("aei-u", found + 1);
	}

	cout << str << '\n' <<endl;
	
	cout << "\nfind(string/char*,pos)���ַ�����������һ��.....\n";
	auto fpos = str.find("bb");
	if (fpos != string::npos){
		cout << "find pos ==" << fpos << "  element =" << str[fpos] << endl;
	}
}
void std_find_first_of(){
	string  str = "abcbb,-;bbf";
	string  substr = "eeeeeekad";//������һ���������κ�һ����
	auto  iter = find_first_of(str.begin(), str.end(), substr.begin(), substr.end());
	//auto  iter = find_first_of(str.begin(), str.end(), 'b', 1 );
	if (iter != str.end())
	{
		cout << "string find pos = " << *iter << endl << endl;
	}
	else
		cout << "connot find....\n\n";


	char a[] = ",";
	auto  iter2 = find_first_of(str.begin(), str.end(), a, a + 1);  //ָ����Ȼ�ǿ�����Ϊ�������ġ�����
	char *a = "abcdef";
	//auto iterxxx = find_first_of(a, a + 3, 'a');
	if (iter2 != str.end())
	{
		cout << "string find pos = " << *iter2 << endl << endl;
	}
	else
		cout << "connot find....\n\n";
	cout << "\nstd����findֻ����һ��ֵ��������һ����������ʹ��search��������\n";
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
	cout << "\nsearch��һ����������std�����find����\n";
	it = std::search(haystack.begin(), haystack.end(), needle1, needle1 + 4);//���һ����ʹ�����飬ҲҪ����һ��...

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
// sting�ض�����
void string_substr(){
	cout << "string �ضϣ�������\\0ֻ�ܶ�char*��������string����δ����\\0����" << endl;
	string str = "abc,def,ghi";
	str[3] = '\0';
	string substr(str.substr()); //��û�нضϣ�����һ���� substr(0, npos)Ĭ�ϣ������������һ��
	cout << "sub.str=" << substr << '\t' << "str =" << str ;
	cout << "            �ض�ʧ��.....\n";

	char* strch = const_cast<char*>(str.c_str());
	cout << "strch  =" << strch << '\t' << "str =" << str << "...�ضϳɹ�......\n\n";

	string substr2 = str.substr(4, 5);  //4���濪ʼ��ȡ5��
	cout << "str.substr(4,7) =" << substr2 << endl;
	string substr3 = str.substr(4);
	cout << "str.substr(4) =" << substr3 << endl;

	cout << "\nerase�������������� \n";  //erase�ǲ�����n1��ʼ��n2�����ַ���
	cout << "str.erase(positin, len)===" << str.erase(3, 8) << endl;
	str = "abc,def,ghi";
	cout << "str.erase(iter.begin(), end())" << *str.erase(str.begin() + 3, str.begin() + 8) << endl;//���ᶪʧ��ַ
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