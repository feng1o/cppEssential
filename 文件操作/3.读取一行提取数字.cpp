#if 0
// http://www.cnblogs.com/TenosDoIt/p/3724234.html
���ڵ�һ�������ǿ�����c��c++���ַ�������

c���


FILE *fp = fopen("input.txt", "r");
char buf[10000];
while (fgets(buf, 10000, fp))
{
	//��buf����������
}

c++���


ifstream infile("input.txt");


string s;
while (getline(infile, s))
{
	//��s�н���������
}



����������������ǽ���������ʱ�䣬�����ַ�����ʱ����˵��getline��fgetsЧ�ʻ�����ͬ��





���ڵڶ�������һ���ַ����н����������������ṩ3�з���, Ϊ�˼򵥣�����ֻ�Ƿ��ش��ַ����н�������������������û�а����Ǵ�������

����1�������ַ�����istringstream
int getInt(string &s)
{
	istringstream iss(s);
	int num, res = 0;
	while (iss >> num)
		res++;
	return res;
}



����2������strstr������atoi����


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



����3������strtok�������ú����÷��ɲο����ں���strtok��strtok_r��ʹ��Ҫ���ʵ��ԭ��һ������atoi����
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