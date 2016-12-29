#define  _CRT_SECURE_NO_WARNINGS

#include "head.h"
typeDvdInfo getDvdInfo(char* fileDvdInfo, char* dvdName){
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
			fclose(fp);
			break;
		}
		while (dvdinfo.nActors--){
			fread(name, sizeof(name), 1, fp);
		}
	}
	return dvdinfo;
}
void changeDvdAfterRent(char* fileDvdInfo, typeDvdInfo Rdvdinfo){
	char name[20];
	FILE* fp = fopen(fileDvdInfo, "rb+");
	if (!fp)
	{
		printf("open file errror~!\n");
		exit(-1);
	}
	typeDvdInfo dvdinfo;
	while (fread(&dvdinfo, sizeof(typeDvdInfo), 1, fp)){
		if (strcmp(dvdinfo.name, Rdvdinfo.name) == 0)
		{
			fseek(fp, -(int)sizeof(typeDvdInfo), SEEK_CUR);
			--dvdinfo.nCopy;
			++dvdinfo.nRent;
			fwrite(&dvdinfo, sizeof(typeDvdInfo), 1, fp);
			fclose(fp);
			return;
		}
		while (dvdinfo.nActors--){
			fread(name, sizeof(name), 1, fp);
		}
		if (feof(fp)){
			break;
		}

	}
	fclose(fp);
	return;
}
void changeCustomRentHistory(char* fileCustomInfo, typeDvdInfo dvdinfo, char* id){
	int k = -1;
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
			break;
		}
	}
	printf("This DVD need deposit fee: %f, and the customer has pending money : %f\n", dvdinfo.depositFee, custominfo.depositFee);
	if (custominfo.depositFee - dvdinfo.depositFee >= 0.000001){
		printf("Ok, this account has enough money to rent this book...\n");
		custominfo.depositFee -= dvdinfo.depositFee;
	}
	else{
		printf("Sorry, this customer need : %f dollars to rent this book..\n", dvdinfo.depositFee - custominfo.depositFee);
		custominfo.depositFee = 0;
	}

	//refresh rent history
	while (++k < 5){
		if (strcmp(custominfo.rentHistoryInfo[k].dvdName, "$$") != 0){
			continue;
		}
		strcpy(custominfo.rentHistoryInfo[k].dvdName, dvdinfo.name);
		printf("Input rent time, such as 20160101 :");
		fflush(stdin);
		gets(custominfo.rentHistoryInfo[k].rentTime);
		custominfo.rentHistoryInfo[k].depositFee = dvdinfo.depositFee;
		custominfo.rentHistoryInfo[k].dayFee = dvdinfo.dayFee;
		break;
	}
	if (k >= 5){
		printf("Sorry, you have rented too many dvd, please return first~!\n");
		fclose(fp);
		return;
	}
	fseek(fp, -(int)sizeof(typeCustomInfo), SEEK_CUR);
	fwrite(&custominfo, sizeof(typeCustomInfo), 1, fp);
	fclose(fp);
}

typeCustomInfo getCustomInfo(char* fileCustomInfo, char* id){
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
			fclose(fp);
			break;
		}
	}
	fclose(fp);
	return custominfo;
}
void rentDvd(char* fileDvdInfo, char* fileCustomInfo){
	char id[10];
	char dvdName[DVDNAMELEN];
	typeDvdInfo  dvdinfo;
	typeCustomInfo customInfo;
	printf("	Input customer id: ");
	fflush(stdin);
	gets(id);
	if (findCustomInfo(fileCustomInfo, id) == 1){
		while (1){
			printf("If finish rent DVD input : 0 , else input the DVD name:\n");
			fflush(stdin);
			gets(dvdName);
			if (strcmp(dvdName, "0") == 0){
				return;
			}
			if (findDvdInfo(fileDvdInfo, dvdName) == 1){
				dvdinfo = getDvdInfo(fileDvdInfo, dvdName);
				if (dvdinfo.nCopy < 1){
					printf("Sorry, there is no copy to rent... get another?\n");
					continue;
				}
				customInfo = getCustomInfo(fileCustomInfo, id);
				if (customInfo.age < 18 && dvdinfo.childrenFlag == 'Y'){
					printf("Sorry, you are limited to rent this DVD, child forbiden!\n");
				}
				changeCustomRentHistory(fileCustomInfo, dvdinfo, id);
				changeDvdAfterRent(fileDvdInfo, dvdinfo);
			}
			else{
				printf("Sorry, there is no this dvd ~, please choose another one!\n");
			}
		}
	}
	else{
		printf("Sorry, this customer need regist in...can not rent dvd now~!\n");
		return;
	}
}

void changeCustomHistoryAfterReturn(char* fileCustomInfo, typeDvdInfo dvdinfo, char* id){
	int k = -1;
	char nowTime[10];
	float now = 0;
	float rentTime = 0;
	float lastMoney = 0;
	char ch = 'N';
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
			break;
		}
	}
	printf("This DVD need deposit fee: %f, and the customer has pending money : %f\n", dvdinfo.depositFee, custominfo.depositFee);
	printf("Please input the time of today , such as: 20160101:");
	fflush(stdin);
	gets(nowTime);
	now = (float)atoi(nowTime);
	//refresh rent history
	while (++k < 5){
		if (strcmp(custominfo.rentHistoryInfo[k].dvdName, dvdinfo.name) != 0){
			continue;
		}
		rentTime = (float)atoi(custominfo.rentHistoryInfo[k].rentTime);
		if (now - rentTime <= 30)
			lastMoney = (now - rentTime)*custominfo.rentHistoryInfo[k].dayFee;
		else{
			lastMoney = (now - rentTime - 30) * 3 * custominfo.rentHistoryInfo[k].dayFee + 30 * custominfo.rentHistoryInfo[k].dayFee;
		}
		printf("Your rent fee : %f , DVD deposit fee :%f , your account Pend charges : %f\n", lastMoney, dvdinfo.depositFee, custominfo.pendCharges);
		printf("Hello. you will get money : %f \n", custominfo.pendCharges + dvdinfo.depositFee - lastMoney);
		if (custominfo.pendCharges + dvdinfo.depositFee - lastMoney > 0.000001){
			printf("If you save your money in your account , please input :Y, else input N\n");
			scanf("%c", &ch);
			if ('N' == ch){
				custominfo.pendCharges = 0;
			}
			else{
				custominfo.pendCharges = custominfo.pendCharges + dvdinfo.depositFee - lastMoney;
			}
		}
		else{
			custominfo.pendCharges = 0;
			printf("Yout have to give : %f \n", custominfo.pendCharges + dvdinfo.depositFee - lastMoney);
		}
		custominfo.rentHistoryInfo[k].depositFee = 0;
		custominfo.rentHistoryInfo[k].dayFee = 0;
		strcpy(custominfo.rentHistoryInfo[k].dvdName, "$$");
		strcpy(custominfo.rentHistoryInfo[k].rentTime, "$$");
		break;
	}
	if (k >= 5){
		printf("Sorry, there is an error...!\n");
		fclose(fp);
		return;
	}
	fseek(fp, -(int)sizeof(typeCustomInfo), SEEK_CUR);
	fwrite(&custominfo, sizeof(typeCustomInfo), 1, fp);
	fclose(fp);
}
void changeDvdAfterReturn(char* fileDvdInfo, typeDvdInfo Rdvdinfo){
	char name[20];
	FILE* fp = fopen(fileDvdInfo, "rb+");
	if (!fp)
	{
		printf("open file errror~!\n");
		exit(-1);
	}
	typeDvdInfo dvdinfo;
	while (fread(&dvdinfo, sizeof(typeDvdInfo), 1, fp)){
		if (strcmp(dvdinfo.name, Rdvdinfo.name) == 0)
		{
			fseek(fp, -(int)sizeof(typeDvdInfo), SEEK_CUR);
			++dvdinfo.nCopy;
			--dvdinfo.nRent;
			fwrite(&dvdinfo, sizeof(typeDvdInfo), 1, fp);
			fclose(fp);
			return;
		}
		while (dvdinfo.nActors--){
			fread(name, sizeof(name), 1, fp);
		}
		if (feof(fp)){
			break;
		}

	}
	fclose(fp);
	return;
}
void returnDvd(char* fileDvdInfo, char* fileCustomInfo){
	char id[10];
	char dvdName[100];
	typeDvdInfo  dvdinfo;
	printf("	Input customer id: ");
	fflush(stdin);
	gets(id);
	if (findCustomInfo(fileCustomInfo, id) == 1){
		while (1){
			printf("Input the DVD name you want to return: input : 0 means return over! ");
			fflush(stdin);
			gets(dvdName);
			if (strcmp(dvdName, "0") == 0){
				return;
			}
			dvdinfo = getDvdInfo(fileDvdInfo, dvdName);
			changeCustomHistoryAfterReturn(fileCustomInfo, dvdinfo, id);
			changeDvdAfterReturn(fileDvdInfo, dvdinfo);
		}
	}
	else{
		printf("Your id error..., think about it...\n");
	}

}


void RentWorkerDo(int passwdErr){
	while (1){
		char *toolBar = "\n\t\t***********************************************\n"
			"\t\t\tRent Worker, Please select :\n"
			"\t\t0.rent dvd..\n"
			"\t\t1.return dvd \n"
			"\t\t-1.go out!\n"
			"\t\t***********************************************\n\n";
		printf("%s", toolBar);

		int n = 0;
		scanf("%d", &n);
		switch (n){
		case 0:{
			rentDvd("dvdinfo.txt", "custominfo.txt");
			break;
		}
		case 1:{
			returnDvd("dvdinfo.txt", "custominfo.txt");
			break;
		}
		case -1:return;
		default:;
		}
	}

}