
#define  _CRT_SECURE_NO_WARNINGS
#include "exception"
#include "iostream"
#include "string"

using namespace std;

void throwExp(){
	//throw new exception("abc");
	//throw new bad_alloc;

}
int main(){
	string *str = new string("abc");
	//throw exception("abc");
	char m_head_len_c[4];
	sprintf(m_head_len_c, "%d", 123);
	
	cout << "m-hed..." << m_head_len_c << endl;

	cout << "xxx:" << m_head_len_c[0] << m_head_len_c[1] << m_head_len_c[2] << m_head_len_c[3]<< endl;
	int len = static_cast<unsigned int>(m_head_len_c[0]) + (static_cast<unsigned int>(m_head_len_c[1]) << 8) + (static_cast<unsigned int>(m_head_len_c[2]) << 16) + (static_cast<unsigned int>(m_head_len_c[3]) << 24);
	cout << "atoi =" << atoi(m_head_len_c)  << "  ..." << len  << endl;
	try
	{
		throwExp();
	}
	catch (exception* e)
	{
		cout << e->what() << endl;
	}
	return 0;
}