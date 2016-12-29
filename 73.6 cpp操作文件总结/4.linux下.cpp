#if 0
#include <sys/mman.h>  
#include <sys/types.h>  
#include <fcntl.h>  
#include<string.h>  
#include<stdio.h>  
#include <unistd.h>  
#include <sys/stat.h>  

//求子串  
char* substr(const char*str, unsigned long start, unsigned long end);

void replace(const char *ori, const char *dst, int fd, unsigned char *buffer, unsigned long size);

//替换文本. ori:将要替换的字符串、dst:替换的目的字符串, path:文件名  
void replace(const char *ori, const char *dst, const char *path);

int main(int argc, char** argv) // map a normal file as shared mem:  
{
	replace("abc", "123456", "/Users/zctech/Desktop/test.cpp");
}


//求子串  
char* substr(const char*str, unsigned long start, unsigned long end)
{
	unsigned long n = end - start;
	static char stbuf[1024 * 512];
	strncpy(stbuf, str + start, n);
	stbuf[n] = 0;                           //字串最后加上0  
	return stbuf;
}


void replace(const char *ori, const char *dst, int fd, unsigned char *buffer, unsigned long size)
{
	unsigned char *buf = new unsigned char[size];
	unsigned long i = 0;

	unsigned long *dSize = new unsigned long;
	*dSize = size;  //动态文件大小，由于替换数据造成文件加大  

	unsigned char *buffer2 = new unsigned char[size];
	memccpy(buffer2, buffer, sizeof(unsigned char), size);

	long dt = 0;
	while (i < *dSize)
	{
		if (0 == strcmp(ori, substr((char *)buffer2, i, i + strlen(ori))))
		{
			dt += strlen(dst) - strlen(ori);

			//定位到号+ori长的位置读取数据  
			lseek(fd, i + strlen(ori), SEEK_SET);
			read(fd, buf, *dSize - i - strlen(ori));


			//定位到#号+1+length的位置  
			lseek(fd, i + strlen(dst), SEEK_SET);
			write(fd, buf, *dSize - i - strlen(ori));


			//回到#号位置并写入数据  
			lseek(fd, i, SEEK_SET);
			write(fd, dst, strlen(dst));

			//由于size变了,需要修改dSize,将数据存储在临时指针中  
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


//删除注释.path:文件名  
void replace(const char *ori, const char *dst, const char *path)
{

	int fd = open(path, O_RDWR);

	//获取文件大小  
	struct stat sb;
	fstat(fd, &sb);

	unsigned char *start = (unsigned char *)mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (start == MAP_FAILED) /* 判断是否映射成功 */
	{
		printf("映射失败，文件过大或者没有权限");
		return;
	}

	replace(ori, dst, fd, start, sb.st_size);

	close(fd);
	munmap(start, sb.st_size); /* 解除映射 */

}
#endif