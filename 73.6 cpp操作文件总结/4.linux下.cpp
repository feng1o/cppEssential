#if 0
#include <sys/mman.h>  
#include <sys/types.h>  
#include <fcntl.h>  
#include<string.h>  
#include<stdio.h>  
#include <unistd.h>  
#include <sys/stat.h>  

//���Ӵ�  
char* substr(const char*str, unsigned long start, unsigned long end);

void replace(const char *ori, const char *dst, int fd, unsigned char *buffer, unsigned long size);

//�滻�ı�. ori:��Ҫ�滻���ַ�����dst:�滻��Ŀ���ַ���, path:�ļ���  
void replace(const char *ori, const char *dst, const char *path);

int main(int argc, char** argv) // map a normal file as shared mem:  
{
	replace("abc", "123456", "/Users/zctech/Desktop/test.cpp");
}


//���Ӵ�  
char* substr(const char*str, unsigned long start, unsigned long end)
{
	unsigned long n = end - start;
	static char stbuf[1024 * 512];
	strncpy(stbuf, str + start, n);
	stbuf[n] = 0;                           //�ִ�������0  
	return stbuf;
}


void replace(const char *ori, const char *dst, int fd, unsigned char *buffer, unsigned long size)
{
	unsigned char *buf = new unsigned char[size];
	unsigned long i = 0;

	unsigned long *dSize = new unsigned long;
	*dSize = size;  //��̬�ļ���С�������滻��������ļ��Ӵ�  

	unsigned char *buffer2 = new unsigned char[size];
	memccpy(buffer2, buffer, sizeof(unsigned char), size);

	long dt = 0;
	while (i < *dSize)
	{
		if (0 == strcmp(ori, substr((char *)buffer2, i, i + strlen(ori))))
		{
			dt += strlen(dst) - strlen(ori);

			//��λ����+ori����λ�ö�ȡ����  
			lseek(fd, i + strlen(ori), SEEK_SET);
			read(fd, buf, *dSize - i - strlen(ori));


			//��λ��#��+1+length��λ��  
			lseek(fd, i + strlen(dst), SEEK_SET);
			write(fd, buf, *dSize - i - strlen(ori));


			//�ص�#��λ�ò�д������  
			lseek(fd, i, SEEK_SET);
			write(fd, dst, strlen(dst));

			//����size����,��Ҫ�޸�dSize,�����ݴ洢����ʱָ����  
			unsigned char *t = buffer2;

			*dSize += strlen(dst) - strlen(ori);
			buffer2 = new unsigned char[*dSize];
			lseek(fd, 0, SEEK_SET);
			read(fd, buffer2, *dSize);

			delete[]t;
		}
		i++;
	}

	if (dt < 0)
	{
		for (long i = *dSize; i < *dSize - dt; i++)
		{
			*(buffer2 + i) = 32;
		}
		lseek(fd, 0, SEEK_SET);
		write(fd, buffer2, *dSize - dt);
	}

	delete[] buf;
	buf = NULL;
	delete dSize;
	dSize = NULL;
}


//ɾ��ע��.path:�ļ���  
void replace(const char *ori, const char *dst, const char *path)
{

	int fd = open(path, O_RDWR);

	//��ȡ�ļ���С  
	struct stat sb;
	fstat(fd, &sb);

	unsigned char *start = (unsigned char *)mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (start == MAP_FAILED) /* �ж��Ƿ�ӳ��ɹ� */
	{
		printf("ӳ��ʧ�ܣ��ļ��������û��Ȩ��");
		return;
	}

	replace(ori, dst, fd, start, sb.st_size);

	close(fd);
	munmap(start, sb.st_size); /* ���ӳ�� */

}
#endif