#define  _CRT_SECURE_NO_WARNINGS

#include "head.h"
void printAllCustomInfo(char* fileCustomInfo){
	char name[NAMELEN];
	int n = -1;
	FILE* fp = fopen(fileCustomInfo, "rb");
	if (!fp)
	{
		printf("open file errror~!\n");
		exit(-1);
	}
	typeCustomInfo custominfo;
	while (fread(&custominfo, sizeof(typeCustomInfo), 1, fp)){
		if (strcmp(custominfo.id, "$$") != 0){
			printf("\n	CUSTOMER INFO:\n");
			printf("		custom -id			:= %s\n", custominfo.id);
			printf("		custom -name			:= %s\n", custominfo.name);
			printf("		custom -age			:= %d\n", custominfo.age);
			printf("		custom -tel			:= %s\n", custominfo.tel);
			printf("		custom -address			:= %s\n", custominfo.address);
			printf("		custom -depositFee		:= %f\n", custominfo.depositFee);
			printf("		custom -pendCharges		:= %f\n", custominfo.pendCharges);
			printf("		custom -limit			:= %c\n", custominfo.limit);
			printf("		custom 	rentHistory: \n");
			while (++n < 5){
				if (strcmp(custominfo.rentHistoryInfo[n].dvdName, "$$") == 0)
					break;
				printf("			rent DVD name		:%s\n", custominfo.rentHistoryInfo[n].dvdName);
				printf("			rent time		:%s\n", custominfo.rentHistoryInfo[n].rentTime);
				printf("			rent DVD deposit fee	:%f\n", custominfo.rentHistoryInfo[n].depositFee);
				printf("			rent DVD dayfee		:%f\n", custominfo.rentHistoryInfo[n].dayFee);
			}
		}
	}
	fclose(fp);
}
void clearCFile(char* fileCustomInfo){
	remove(fileCustomInfo);
	FILE* fp = fopen(fileCustomInfo, "ab+");
	fclose(fp);
}
void addCustomInfo(char* fileCustomInfo){
	fflush(stdin);
	int n = 0;
	int k = -1;
	FILE* fp = fopen(fileCustomInfo, "ab+");
	if (!fp)
	{
		printf("open file errror~!\n");
		exit(-1);
	}
	typeCustomInfo custominfo;
	printf("Input custom id: ");
	fflush(stdin);
	gets(custominfo.id);
	if (findCustomInfo(fileCustomInfo, custominfo.id) == 1){
		printf("Sorry, this custom is already existed, go back~!\n");
		return;
	}
	printf("Input custom  name: ");
	fflush(stdin); //need
	gets(custominfo.name);

	printf("Input this custom  age (unsigned interger): ");
	scanf("%u", &custominfo.age);
	printf("Input Tel: ");
	fflush(stdin);
	gets(custominfo.tel);
	printf("Input address: ");
	fflush(stdin);
	gets(custominfo.address);
	printf("Input this custom  deposit fee (float number) : ");
	scanf("%f", &custominfo.depositFee);
	printf("Input this custom  pending fee (float number) : ");
	scanf("%f", &custominfo.pendCharges);
	printf("Input custom limit (N/Y): ");
	scanf("%c", &custominfo.limit);
	/*这个方法不行.....
	typeRentInfo rentinfo;
	rentinfo.dayFee = 0;
	rentinfo.depositFee = 0;
	strcpy(rentinfo.dvdName, "$$");
	strcpy(rentinfo.rentTime, "0000");
	while (++k < 5)
	//custominfo.rentHistoryInfo[n] = rentinfo;
	strcpy(&custominfo.rentHistoryInfo[k], &rentinfo);
	*/
	while (++k < 5){
		custominfo.rentHistoryInfo[k].depositFee = 0;
		custominfo.rentHistoryInfo[k].dayFee = 0;
		strcpy(custominfo.rentHistoryInfo[k].dvdName, "$$");
		strcpy(custominfo.rentHistoryInfo[k].rentTime, "$$");
	}
	fwrite(&custominfo, sizeof(typeCustomInfo), 1, fp);
	fclose(fp);
}
void changeCustomInfo(char* fileCustomInfo, int level){
	char id[10];
	int k = -1;
	char flag = 'N';
	fflush(stdin);
	printf("Please  input the customer id : ");
	gets(id);
	if (findCustomInfo(fileCustomInfo, id) == 0){
		printf("there is no this custom ~~! go out ~!");
		return;
	}
	FILE* fp = fopen(fileCustomInfo, "rb+");
	if (!fp)
	{
		printf("open file errror~!\n");
		exit(-1);
	}
	typeCustomInfo custominfo;
	while (fread(&custominfo, sizeof(typeCustomInfo), 1, fp)){
		if (strcmp(custominfo.id, id) == 0)
		{
			fseek(fp, -(int)sizeof(typeCustomInfo), SEEK_CUR);
			printf("custom  name =%s , if you want to change it input Y, else input N!\n", custominfo.name);
			scanf("%c", &flag);
			if (flag == 'Y'){
				printf("Input new name: ");
				fflush(stdin); //need
				gets(custominfo.name);
			}

			printf("custom  age =%d , if you want to change it input Y, else input N!\n", custominfo.age);
			scanf("%c", &flag);
			if (flag == 'Y'){
				printf("Input new age : ");
				scanf("%u", &custominfo.age);
			}
			printf("custom  tel =%s , if you want to change it input Y, else input N!\n", custominfo.tel);
			scanf("%c", &flag);
			if (flag == 'Y'){
				printf("Input new tel : ");
				fflush(stdin);
				gets(custominfo.tel);
			}

			printf("custom  address =%s , if you want to change it input Y, else input N!\n", custominfo.address);
			scanf("%c", &flag);
			if (flag == 'Y'){
				printf("Input new address : ");
				fflush(stdin);
				gets(custominfo.address);
			}

			printf("custom  depositFee =%f , if you want to change it input Y, else input N!\n", custominfo.depositFee);
			scanf("%c", &flag);
			if (flag == 'Y'){
				printf("Input new deposit fee : ");
				scanf("%f", &custominfo.depositFee);
			}

			printf("custom  pendcharges =%f , if you want to change it input Y, else input N!\n", custominfo.pendCharges);
			scanf("%c", &flag);
			if (flag == 'Y'){
				printf("Input new pend charges : ");
				scanf("%f", &custominfo.pendCharges);
			}

			printf("custom  limit =%c , if you want to change it input Y, else input N!\n", custominfo.limit);
			scanf("%c", &flag);
			if (flag == 'Y'){
				printf("Input new limit : ");
				scanf("%f", &custominfo.limit);
			}
			if (level == 0){
				printf("custom 	rentHistory: \n");
				while (++k < 5){
					if (strcmp(custominfo.rentHistoryInfo[k].dvdName, "$$") == 0){
						break;
					}
					printf("	rent DVD name : %s, if you want to change it input Y, else input N!\n", custominfo.rentHistoryInfo[k].dvdName);
					scanf("%c", &flag);
					if ('Y' == flag){
						printf("	INput new dvd name: ");
						fflush(stdin);
						gets(custominfo.rentHistoryInfo[k].dvdName);
					}
					printf("	rent DVD rent time : %s, if you want to change it input Y, else input N!\n", custominfo.rentHistoryInfo[k].rentTime);
					scanf("%c", &flag);
					if ('Y' == flag){
						printf("	INput new rentTime : ");
						fflush(stdin);
						gets(custominfo.rentHistoryInfo[k].rentTime);
					}
					printf("	rent DVD depositfee : %f, if you want to change it input Y, else input N!\n", custominfo.rentHistoryInfo[k].depositFee);
					scanf("%c", &flag);
					if ('Y' == flag){
						printf("	INput new deposit fee : ");
						scanf("%f", &custominfo.rentHistoryInfo[k].depositFee);
					}
					printf("	rent DVD day fee : %f, if you want to change it input Y, else input N!\n", custominfo.rentHistoryInfo[k].dayFee);
					scanf("%c", &flag);
					if ('Y' == flag){
						printf("	INput new day fee : ");
						scanf("%f", &custominfo.rentHistoryInfo[k].dayFee);
					}
				}
			}
			fwrite(&custominfo, sizeof(typeCustomInfo), 1, fp);
			fclose(fp);
			return;
		}
		if (feof(fp)){
			break;
		}
	}
	fclose(fp);
	return;
}

int findCustomInfo(char* fileCustomInfo, char* id){
	FILE* fp = fopen(fileCustomInfo, "rb");
	if (!fp)
	{
		printf("open file %s errror~!\n", fileCustomInfo);
		exit(-1);
	}
	typeCustomInfo custominfo;
	while (fread(&custominfo, sizeof(typeCustomInfo), 1, fp)){
		if (strcmp(custominfo.id, id) == 0)
		{
			fclose(fp); return 1;
		}
	}
	fclose(fp);
	return 0;
}
void RegistWorkerDo(int passwdErr){
	char* fileCustomInfo = "custominfo.txt";
	while (1){
		char *toolBar = "\n\t\t***********************************************\n"
			"\t\t\t Registration Worker, Please select :\n"
			"\t\t-1.clear the file\n"
			"\t\t0.show all custom info..\n"
			"\t\t1.regist a new custom\n"
			"\t\t2.change custominfo\n"
			"\t\t3.go out!\n"
			"\t\t***********************************************\n\n";
		printf("%s", toolBar);

		int n = 0;
		scanf("%d", &n);
		switch (n){
		case -1:{
			clearCFile(fileCustomInfo);
			break;
		}
		case 0:{
			printAllCustomInfo(fileCustomInfo);
			break;
		}
		case 1:{
			addCustomInfo(fileCustomInfo);
			break;
		}
		case  2:{
			changeCustomInfo(fileCustomInfo, 1);
			break;
		}
		case 3:return;
		default:printf("input error..continue...\n");
		}
	}

}

void delCustomInfo(char* fileCustomInfo){
	char id[10];
	int k = -1;
	char flag = 'N';
	fflush(stdin);
	printf("Please  input the  del customer id : ");
	gets(id);
	if (findCustomInfo(fileCustomInfo, id) == 1){
		printf("there is no this custom ~~! go out ~!");
		return;
	}
	FILE* fp = fopen(fileCustomInfo, "rb+");
	if (!fp)
	{
		printf("open file errror~!\n");
		exit(-1);
	}
	typeCustomInfo custominfo;
	while (fread(&custominfo, sizeof(typeCustomInfo), 1, fp)){
		if (strcmp(custominfo.id, id) == 0)
		{
			fseek(fp, -(int)sizeof(typeCustomInfo), SEEK_CUR);
			strcpy(custominfo.id, "$$");
			fwrite(&custominfo, sizeof(typeCustomInfo), 1, fp);
			fclose(fp);
			return;
		}
		if (feof(fp)){
			break;
		}
	}
	fclose(fp);
	return;
}