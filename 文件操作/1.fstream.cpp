#if 0


#define  _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include "iostream"
#include "fstream"
#include "string"
#include "fstream"

using namespace std;


int main(){
	/*freopen("data.out", "r+", stdin); //first read？ if not exist ？
	freopen("data.out", "w", stdout);

	cout << "abcdeg" << endl;
	string str;
	cin >> str;
	cout << str << endl;*/

	//ofstream of;
	//of.open("file.txt", ofstream::out|ofstream::binary);//不加binary可能不同
	//string str1 = "tdst ......";
	//of.write(str1.c_str(), strlen(str1.c_str()));
	////of.put('c');
	//of.close();

	ifstream is("pic.png", ifstream::binary);
	if (is)
	{
		is.seekg(0, is.end);
		int len = is.tellg();
		cout << "file length = " <<  len << endl;
		is.seekg(0, is.beg);

		char *buf = new char[len];
		is.read(buf, len);
		//cout << "read = " << buf << endl;
		is.close();

		ofstream of;
		of.open("xx.png", ofstream::out|ofstream::binary);//不加binary可能不同
		//string str1 = "tdst ......";
		of.write(buf, len);
		of.close();
		delete[] buf;
	}

}
#endif