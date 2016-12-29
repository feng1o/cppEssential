#if 0
// http://www.cnblogs.com/TenosDoIt/p/3724234.html
对于第一步，我们可以有c、c++两种风格的做法

c风格：


FILE *fp = fopen("input.txt", "r");
char buf[10000];
while (fgets(buf, 10000, fp))
{
	//从buf解析出整数
}

c++风格：


ifstream infile("input.txt");


string s;
while (getline(infile, s))
{
	//从s中解析出整数
}



经过测试如果不考虑解析整数的时间，这两种方法耗时相差不大，说明getline和fgets效率基本相同。





对于第二步，从一行字符串中解析出整数，以下提供3中方法, 为了简单，我们只是返回从字符串中解析出的整数个数，并没有把他们存入数组

方法1：利用字符串流istringstream
int getInt(string &s)
{
	istringstream iss(s);
	int num, res = 0;
	while (iss >> num)
		res++;
	return res;
}



方法2：利用strstr函数和atoi函数


int getInt(const char *buf)
{
	const char *loc = buf;
	int res = 0;
	atoi(buf);
	loc = strstr(buf, " ");
	while (loc != NULL)
	{
		atoi(loc + 1);
		res++;
		loc = strstr(loc + 1, " ");
	}
	return res;
}



方法3：利用strtok函数（该函数用法可参考关于函数strtok和strtok_r的使用要点和实现原理（一））和atoi函数
int getInt(char *buf)
{
	char *p = strtok(buf, " ");
	int res = 0;
	while (p)
	{
		atoi(p);
		res++;
		p = strtok(NULL, " ");
	}
	return res;
}
#endif