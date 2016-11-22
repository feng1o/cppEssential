#if 01

#define  _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(){
	char a[] = { '0', '0', '0', '1', '2' };
	printf("... %d\n", atoi("000000000012"));
	printf("... %d\n", atoi(a));
	
	FILE* fp;
	if ((fp = fopen("pic.png", "rb+")) == NULL){
		perror("open error...\n");
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	printf("length= %d", ftell(fp));
	rewind(fp);
	fseek(fp, 0, SEEK_SET); //begin

	char* buf = (char*)malloc(sizeof(char)*len);
	fread(buf, len, 1, fp);
	fclose(fp);

	fp = fopen("xx1.png", "wb+");
	fwrite(buf, len, 1, fp);
	fclose(fp);
	free(buf);
	time_t t = time(NULL);
	printf("\n%d\n", t);

	char Ctime[15];
	sprintf(Ctime, "pic_%d", t);
	printf("ctime=%s", Ctime);
	return 0;
}
#endif