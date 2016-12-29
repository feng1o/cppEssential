#ifndef _HEADER_H_
#define _HEADER_H_

#define DCLEAR
#define CCLEAR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
	DVDNAMELEN = 100,
	NAMELEN = 20
};
//account struct structure;
typedef struct strDvdInfo typeDvdInfo;
typedef struct strCustomInfo typeCustomInfo;
typedef struct strRentInfo     typeRentInfo;
struct strRentInfo{
	char			dvdName[DVDNAMELEN];
	char			rentTime[10]; //20161020
	float			depositFee;
	float			dayFee;
};
struct strDvdInfo{
	char			name[DVDNAMELEN];  //dvd name;
	unsigned int	nCopy;      //copies number;
	unsigned int	nRent;
	char			direcotr[NAMELEN];  //director name;
	char            childrenFlag; //
	char            dvdType[30];
	float			depositFee;
	float			dayFee;
	//char			actors[20]; //protagonist, 
	int				nActors;    //
};

struct strCustomInfo{
	char 			id[10];
	char			name[20];
	unsigned int	age;
	char			tel[20];
	char			address[200];
	float			depositFee;
	float			pendCharges;
	char			limit;
	typeRentInfo    rentHistoryInfo[5];
};

//function names
void BranchManagerDo(int passwdErr);
void RegistWorkerDo(int passwdErr);
void RentWorkerDo(int passwdErr);


void addDvdInfo(char* fileDvdInfo);
void printAllDvdInfo(char* fileDvdInfo);
int  findDvdInfo(char* fileDvdInfo, char* dvdName);
int	 delDvdInfo(char* fileDvdInfo);
void changeDvdInof(char* fileDvdInfo);
void checkStockInfo(char* fileDvdInfo);

//registration worker 
void printAllCustomInfo(char* fileCustomInfo);
void addCustomInfo(char* fileCustomInfo);
void changeCustomInfo(char* fileCustomInfo, int level);
int findCustomInfo(char* fileCustomInfo, char* id);

//rentWorker 
void rentDvd(char* fileDvdInfo, char* fileCustomInfo);
void returnDvd(char* fileDvdInfo, char* fileCustomInfo);

typeDvdInfo getDvdInfo(char* fileDvdInof, char* dvdName);
void changeCustomRentHistory(char* fileCustomInfo, typeDvdInfo dvdinfo, char* id);
void changeDvdAfterRent(char* fileDvdInfo, typeDvdInfo dvdinfo);
void changeCustomHistoryAfterReturn(char* fileCustomInfo, typeDvdInfo dvdinfo, char* id);
void changeDvdAfterReturn(char* fileDvdInfo, typeDvdInfo dvdinfo);

void delCustomInfo(char* fileCustomInfo);
typeCustomInfo getCustomInfo(char* fileCustominfo, char* id);

#endif