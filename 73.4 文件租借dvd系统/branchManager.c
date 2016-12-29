#define  _CRT_SECURE_NO_WARNINGS

#include "head.h"
void printAllDvdInfo(char* fileDvdInfo){
	char name[20];
	FILE* fp = fopen(fileDvdInfo, "rb+");
	if (!fp)
	{
		printf("open file errror~!\n");
		exit(-1);
	}
	typeDvdInfo dvdinfo;
	while (fread(&dvdinfo, sizeof(typeDvdInfo), 1, fp)){
		if (strcmp(dvdinfo.name, "$$") != 0){
			printf("\n	DVD INFO:\n");
			printf("		dvd-name		:= %s\n", dvdinfo.name);
			printf("		dvd-ncopy		:= %u\n", dvdinfo.nCopy);
			printf("		dvd-director		:= %s\n", dvdinfo.direcotr);
			printf("		dvd-nRent		:= %d\n", dvdinfo.nRent);
			printf("		dvd-childrenFlag	:= %c\n", dvdinfo.childrenFlag);
			printf("		dvd-dvdType		:= %s\n", dvdinfo.dvdType);
			printf("		dvd-depositFee		:= %f\n", dvdinfo.depositFee);
			printf("		dvd-dayFee		:= %f\n", dvdinfo.dayFee);
			printf("		dvd-actors		:= ");
		}
		while (dvdinfo.nActors--){
			fread(name, sizeof(name), 1, fp);
			if (strcmp(dvdinfo.name, "$$") != 0)
				printf("%s, ", name);
		}
		printf("\n");
	}
	fclose(fp);
}
int  findDvdInfo(char* fileDvdInfo, char* dvdName){
	char name[20];
	FILE* fp = fopen(fileDvdInfo, "rb");
	if (!fp)
	{
		printf("open file errror~!\n");
		exit(-1);
	}
	typeDvdInfo dvdinfo;
	while (fread(&dvdinfo, sizeof(typeDvdInfo), 1, fp)){
		if (strcmp(dvdinfo.name, dvdName) == 0)
		{
			fclose(fp); return 1;
		}
		while (dvdinfo.nActors--){
			fread(name, sizeof(name), 1, fp);
		}
	}
	fclose(fp);
	return 0;
}

void clearFile(char* fileDvdInfo){
	remove(fileDvdInfo);
	FILE* fp = fopen(fileDvdInfo, "ab+");
	fclose(fp);
}
void addDvdInfo(char* fileDvdInfo){
	fflush(stdin);
	int n = 0;
	char actorNames[20];

	FILE* fp = fopen(fileDvdInfo, "ab+");//w+文件存在，会覆盖源文件，删除了一样，把源文件内容清空了... a不会，，改写文件内容，必须是r+，不能是w+
	if (!fp)
	{
		printf("open file errror~!\n");
		exit(-1);
	}
	typeDvdInfo dvdinfo;
	printf("Input dvd name: ");
	fflush(stdin); //need  //gets前一定要，fflush()否则，前面有输入会读取一个\n回车符
	gets(dvdinfo.name);
	if (findDvdInfo(fileDvdInfo, dvdinfo.name) == 1){
		printf("___This dvd record exists, you can change its info...\n");
		return;
	}
	printf("Input this dvd copies ( usigned int): ");
	scanf("%u", &dvdinfo.nCopy);
	dvdinfo.nRent = 0;
	printf("Input director: ");
	fflush(stdin);
	gets(dvdinfo.direcotr);
	printf("This dvd is children forbiden? Y/N: ");
	scanf("%c", &dvdinfo.childrenFlag);
	printf("Input this dvd type: \n"
		"	such as horror action drama  or love etc.:\n"
		"	input: ");
	fflush(stdin);
	gets(dvdinfo.dvdType);
	printf("Input this dvd deposit fee (float number) : ");
	scanf("%f", &dvdinfo.depositFee);
	printf("Input this dvd rent fee one day (float): ");
	scanf("%f", &dvdinfo.dayFee);
	printf("Iput actors number and actor names separated by enter keyborad, such as: \n"
		"	2\n"
		"	Andy king\n"
		"	Jo	yaso\n");
	scanf("%d", &n);
	dvdinfo.nActors = n;
	fwrite(&dvdinfo, sizeof(typeDvdInfo), 1, fp);
	while (n--){
		fflush(stdin);
		gets(actorNames);
		fwrite(actorNames, sizeof(actorNames), 1, fp);
	}
	fclose(fp);
}
int	 delDvdInfo(char* fileDvdInfo){
	char name[NAMELEN];
	char DVDName[DVDNAMELEN];
	fflush(stdin);
	printf("Please input the del dvd name: ");
	gets(DVDName);
	FILE* fp = fopen(fileDvdInfo, "rb+");
	if (!fp)
	{
		printf("open file errror~!\n");
		exit(-1);
	}
	typeDvdInfo dvdinfo;
	while (fread(&dvdinfo, sizeof(typeDvdInfo), 1, fp)){
		if (strcmp(dvdinfo.name, DVDName) == 0)
		{
			fseek(fp, -(int)sizeof(typeDvdInfo), SEEK_CUR);
			strcpy(dvdinfo.name, "$$");
			fwrite(&dvdinfo, sizeof(typeDvdInfo), 1, fp);
			fclose(fp);
			printf("Del dvd info ok>~! \n");
			//printAllDvdInfo(fileDvdInfo);
			return 1;
		}
		while (dvdinfo.nActors--){
			fread(name, sizeof(name), 1, fp);
		}
		if (feof(fp)){
			break;
		}
	}
	fclose(fp);
	printf("Sorry there is no this dvd~!\n");
	return 0;
}

void changeDvdInof(char* fileDvdInfo){
	char dvdname[DVDNAMELEN];
	int flag = 0;
	fflush(stdin);
	printf("Please  input the dvd name: ");
	gets(dvdname);
	if (findDvdInfo(fileDvdInfo, dvdname) == 0){
		printf("there is no this dvd~~! go out ~!");
		return;
	}
	FILE* fp = fopen(fileDvdInfo, "rb+");
	if (!fp)
	{
		printf("open file errror~!\n");
		exit(-1);
	}
	typeDvdInfo dvdinfo;
	while (fread(&dvdinfo, sizeof(typeDvdInfo), 1, fp)){
		if (strcmp(dvdinfo.name, dvdname) == 0)
		{
			fseek(fp, -(int)sizeof(typeDvdInfo), SEEK_CUR); //转为int，家-，否则错误
			printf("\t\t----------------------------------------------\n"
				"\t\t	What do you want to change?\n"
				"\t	1.copies\n"
				"\t	2.nRent\n"
				"\t	3.depositfee\n"
				"\t	4.dayfee\n"
				"\t	0.do nothing, go back\n"
				"\t\t-----------------------------------------------\n\n");
			scanf("%d", &flag);
			switch (flag){
			case  1:{
				printf("Input new copies: ");
				scanf("%u", &dvdinfo.nCopy);
				break;
			}
			case  2:{
				printf("Input new nRent: ");
				scanf("%u", &dvdinfo.nRent);
				break;
			}
			case  3:{
				printf("Input new deposit fee: ");
				scanf("%f", &dvdinfo.depositFee);
				break;
			}
			case  4:{
				printf("Input new day fee: ");
				scanf("%f", &dvdinfo.dayFee);
				break;
			}
			default:  {
				fclose(fp);
				return;
			}
			}
			fwrite(&dvdinfo, sizeof(typeDvdInfo), 1, fp);
			fclose(fp);
			return 1;
		}
		if (feof(fp)){
			break;
		}
	}
	fclose(fp);
	printf("Sorry there is no this dvd~!\n");
	return 0;
}

void checkStockInfo(char* fileDvdInfo){
	char name[20];
	FILE* fp = fopen(fileDvdInfo, "rb+");
	if (!fp)
	{
		printf("open file errror~!\n");
		exit(-1);
	}
	typeDvdInfo dvdinfo;
	while (fread(&dvdinfo, sizeof(typeDvdInfo), 1, fp)){
		if (strcmp(dvdinfo.name, "$$") != 0){
			printf("\n	DVD STOCK INFO:\n");
			printf("		dvd-ncopy		:= %u\n", dvdinfo.nCopy);
			printf("		dvd-nRent		:= %d\n", dvdinfo.nRent);
			while (dvdinfo.nActors--){
				fread(name, sizeof(name), 1, fp);
			}
		}
	}
	fclose(fp);
}


void BranchManagerDo(int passwdErr){
	/*printf("Clean the record~? input y/Y/n/N\n");
	char ch;
	scanf("%c", &ch);
	if (ch != 'Y' && ch != 'y' && ch != 'n' && ch != 'N'){
	printf("  input error~~~input y/Y/n/N~! \n");
	exit(-1);
	}
	if (ch == 'y' || ch == 'Y'){
	GRefreshFlag = 'Y';
	}*/
	char* fileDvdInfo = "dvdinfo.txt";
	/*
	1.add dvdinfo
	2.del addinfo
	3.change dvdinfo
	4.change rent fee
	5.change customer info
	6.del   customer
	7.check stock
	*/
	while (1){
		char *toolBar = "\n\t\t*****************************************\n"
			"\t\t\t Branch Manager, Please select :\n"
			"\t\t-1.clear the file\n"
			"\t\t0.show all dvd info..\n"
			"\t\t1.add dvdinfo \n"
			"\t\t2.del addinfo\n"
			"\t\t3.change dvdinfo\n"
			"\t\t4.change customer info\n"
			"\t\t5.del   customer\n"
			"\t\t6.check stock\n"
			"\t\t7.go out!\n"
			"\t\t*****************************************\n\n";
		printf("%s", toolBar);
		int n = 0;
		scanf("%d", &n);
		switch (n){
		case -1:{
			clearFile(fileDvdInfo);
			break;
		}
		case 1:{
			addDvdInfo(fileDvdInfo);
			break;
		}
		case 2:{
			delDvdInfo(fileDvdInfo);
			break;
		}
		case 3:{
			changeDvdInof(fileDvdInfo);
			break;
		}
			   //case 4:{}
		case 4:{
			changeCustomInfo("custominfo.txt", 0);
			break;
		}
		case 5:{
			delCustomInfo("custominfo.txt");
			break; }
		case 6:{
			checkStockInfo(fileDvdInfo);
			break;
		}
		case 0:{
			printAllDvdInfo(fileDvdInfo); break;
		}
		case 7:return;
		default:;
		}
	}
}