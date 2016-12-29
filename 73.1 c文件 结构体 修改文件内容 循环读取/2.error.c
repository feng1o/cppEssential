#if 0
/*
FileName: main.c
input:
output:

Funciton:
1.first you need creat your account
2.if you want to change your account money ,choose 1; else if you want to play the games , input 2;
3.this games is guess the number which is a pseudo-random between 0 - 36; if you get it ,you will win 10$, if you faulure ,you will loss 10$, of course if you want to play the game , you must have more than $10;
*/

/*
1.读写结构体到文件,fwrite(&account, sizeof(typeAccount), 1, fp);,fread()
2.循环读取文件>>>>，不要使用feof可能会最后一个读两次，而且不能结束，见2使用while(fread() != 1)来保证，在while里面判定
	while (fread(&racct, sizeof(racct), 1, fp)){
		if (strcmp(racct.name, acct.name) == 0 && 0 == strcmp(racct.passWd, acct.passWd)) // find the account 
		{
			fseek(fp, -(int)sizeof(typeAccount), SEEK_CUR); //rewrite the accounts values;
			fwrite(&acct, sizeof(typeAccount), 1, fp);
			fclose(fp);
			return racct.money;
		}
		if (feof(fp)){
			break;
		}
	}
3.修改文件里面某个值：fseek，找到指定位置，直接write对应的就会覆盖了：http://blog.chinaunix.net/uid-25958655-id-4319946.html
	while (fread(&racct, sizeof(racct), 1, fp)){
		if (strcmp(racct.name, acct.name) == 0 && 0 == strcmp(racct.passWd, acct.passWd)) // find the account 
		{
			fseek(fp, -(int)sizeof(typeAccount), SEEK_CUR); //rewrite the accounts values;
			fwrite(&acct, sizeof(typeAccount), 1, fp);
			fclose(fp);
			return racct.money;
		}
		if (feof(fp)){
			break;
		}
	}
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//account struct structure;
typedef struct accountStr typeAccount;
struct accountStr{
	char name[20];
	char passWd[12];
	unsigned int  money;
};

//get randNum 
int CreatRandNum(){
	time_t tm;
	tm = time(&tm);
	srand((unsigned int)tm);
	return rand() % 37;
}

/*
users can use this function to creat an account which includes his name ,money, passwd...
*/
void creatAccount(char name[20], char pass[12], unsigned int money){
	FILE *fp = fopen("account.txt", "ab+");
	if (!fp)
	{
		fprintf(stderr, "open file error! \n");
		exit(-1);
	}
	typeAccount account;
	strcpy(account.name, name);
	//account.name = name;
	account.money = money;
	strcpy(account.passWd, pass);
	//account.passWd = pass;
	if (!fp)
	{
		printf("errror!\n");
		exit(-1);
	}
	//fseek(fp, 0, SEEK_END);
	fwrite(&account, sizeof(typeAccount), 1, fp);

	//rewind(fp);
	//typeAccount  acct;
	//fread(&acct, sizeof(acct), 1, fp);
	//printf("name = %s , passwd = %s , money = %u \n", acct.name, acct.passWd, acct.money);
	fclose(fp);
}
void printFile(){
	FILE *fp = fopen("account.txt", "rb+");
	if (!fp)
	{
		fprintf(stderr, "open file error! \n");
		exit(-1);
	}
	typeAccount racct;
	while (fread(&racct, sizeof(racct), 1, fp)){

		printf("-++++++++++-name = %s , passwd = %s , money = %u \n", racct.name, racct.passWd, racct.money);
		if (feof(fp)){
			printf("feof....\n");
			break;
		}
	}
	fclose(fp);
}

int changeMoney(typeAccount acct){
	FILE *fp = fopen("account.txt", "rb+");
	if (!fp)
	{
		fprintf(stderr, "open file error! \n");
		exit(-1);
	}
	int i = 0;
	typeAccount racct;
	while (fread(&racct, sizeof(racct), 1, fp)){
		if (strcmp(racct.name, acct.name) == 0 && 0 == strcmp(racct.passWd, racct.passWd))
		{
			fseek(fp, -(int)sizeof(typeAccount), SEEK_CUR);
			fwrite(&acct, sizeof(typeAccount), 1, fp);
			fclose(fp);
			return racct.money;
		}
		if (feof(fp)){
			break;
		}
	}
	fclose(fp);
	return -1;
}
int findAccount(typeAccount acct){
	FILE *fp = fopen("account.txt", "rb+");
	if (!fp)
	{
		fprintf(stderr, "open file error! \n");
		exit(-1);
	}
	int i = 0;
	typeAccount racct;
	/*错误思路
	while(feof(fp)){
		fread().......;
		do ...

		}这样会导致最后一个数据读了两次，且出错.....

	*/
	while (fread(&racct, sizeof(racct), 1, fp)){
		////if (fread(&racct, sizeof(racct), 1, fp) == 1){
		//	printf("name = %s , passwd = %s , money = %u \n", racct.name, racct.passWd, racct.money);
		////}
		//printf("---name = %s , passwd = %s , money = %u \n", racct.name, racct.passWd, racct.money);
		if (strcmp(racct.name, acct.name) == 0 && 0 == strcmp(racct.passWd, racct.passWd))
		{
			//printf("find .......\n");
			//fseek(fp, -(int)sizeof(typeAccount), SEEK_CUR);
			//fwrite(&acct, sizeof(typeAccount), 1, fp);
			fclose(fp);
			return racct.money;
		}

		//fseek(fp, sizeof(typeAccount), SEEK_CUR);
		//fgetc(fp);
		if (feof(fp)){
			//printf("feof....\n");
			break;
		}
	}
	//printf("close file...\n");
	fclose(fp);
	return -1;
}
void changeAccontMoney(){
	unsigned int money = 0;
	printf("Pleas input account name , account passwd, new account money ~!\n\n");
	typeAccount account;
	scanf("%s %s %u", &account.name, &account.passWd, &account.money);
	int flag = changeMoney(account);
	if (flag == -1){
		printf("Sorry, there is no this account~! \n\n");
	}
	else{
		printf("The money changed..\n\n");
	}
}

void playGame(){
	printf("Pleas input account name , account passwd:\n");
	typeAccount account;
	scanf("%s %s", &account.name, &account.passWd);
	int flag = findAccount(account);
	if (flag == -1){
		printf("Sorry, there is no this account, continue~! \n\n");
	}

	else{
		while (1){
			if (flag < 10){
				printf("This account has no enough money to play the games ~@! \n");
				break;
			}
			else{
				printf(" Congratulations， your account has enough money, $%d to play the games~! \n", flag);
			}
			printf("OK...Start the game ~~~~: \n"
				"     please  input a number  between 0 - 36~~!\n"
				"     such as: 1 \n"
				"     tip: input <0 will treminate the game !\n");
			int guess = -1;
			scanf("%d", &guess);
			if (guess < 0)
				break;
			int result = CreatRandNum();
			if (result == guess)
			{
				flag += 10;
				printf(" \nOk, you win~, your money is $%d \n", flag);
			}
			else{
				flag -= 10;
				printf(" \nSorry, you Failure~, your money is $%d \n", flag);
			}

		}
	}
	account.money = flag;
	changeMoney(account);

}
//main 
int main(){
	FILE *fp = fopen("account.txt", "wt+");
	if (fp)
	{
		remove("account.txt");
	}

	printf("Please input the number of account you will creat, if you want to terminate, please input 0 ! \n");
	int n = 0;
	scanf("%d", &n);
	if (n <= 0){
		printf("terminated ~!~!");
		exit(-1);
	}
	while (n--){
		printf("Pleas input account name which less than 20 characters, account passwd which more than 6 and less than 12 characters; and the money which is unsigned integer ~! such as: andy 123456  100  \n\n");
		typeAccount account;
		scanf("%s %s %u", &account.name, &account.passWd, &account.money);
		creatAccount(account.name, account.passWd, account.money);
	}

	while (1){
		printf("Please chose what you will do:\n"
			"    1:change your account money~~\n"
			"    2:start play the games~!\n");
		int mode = -1;
		scanf("%d", &mode);
		if (mode == 1)
		{

			changeAccontMoney();
			//printFile();
		}
		else if (2 == mode)
		{
			playGame();
		}

	}
	return 0;
}
#endif