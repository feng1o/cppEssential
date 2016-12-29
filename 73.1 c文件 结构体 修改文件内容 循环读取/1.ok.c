/*proj6 题目
FileName: main.c
input: undefined
output: undefined
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
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


//account struct structure;
typedef struct accountStr typeAccount;
struct accountStr{
	char name[20];  //account names less than 20 words
	char passWd[12]; //pass word
	unsigned int  money;
};

//get randNum  0-36
int CreatRandNum(){
	time_t tm;
	tm = time(&tm);   // time_t used as the seed
	srand((unsigned int)tm);  //random seed ,the time
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
		exit(-1);//open file error...
	}
	typeAccount account;
	strcpy(account.name, name);
	account.money = money;
	strcpy(account.passWd, pass);
	if (!fp)
	{
		printf("errror!\n");
		exit(-1);
	}
	fwrite(&account, sizeof(typeAccount), 1, fp); //write the account to the file
	fclose(fp);
}

/*just used for testing the program*/
void printFile(){
	FILE *fp = fopen("account.txt", "rb+");
	if (!fp)
	{
		fprintf(stderr, "open file error! \n");
		exit(-1);
	}
	typeAccount racct;
	while (fread(&racct, sizeof(racct), 1, fp)){ //print acounts 

		printf("-++++++++++-name = %s , passwd = %s , money = %u \n", racct.name, racct.passWd, racct.money);
		if (feof(fp)){
			printf("feof....\n");
			break;
		}
	}
	fclose(fp);
}

// change the account money~
int changeMoney(typeAccount acct){
	FILE *fp = fopen("account.txt", "rb+");
	/*r+具有读写属性，从文件头开始写，保留原文件中没有被覆盖的内容；
		w+具有读写属性，写的时候如果文件存在，会被清空，从头开始写。*/
	if (!fp)
	{
		fprintf(stderr, "open file error! \n");
		exit(-1);   //open error
	}
	int i = 0;
	typeAccount racct;
	while (fread(&racct, sizeof(racct), 1, fp)){
		if (strcmp(racct.name, racct.name) == 0 && 0 == strcmp(racct.passWd, acct.passWd)) // find the account 
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
	fclose(fp);
	return -1;
}

//find the account is exisited
int findAccount(typeAccount acct){
	FILE *fp = fopen("account.txt", "rb+");
	if (!fp)
	{
		fprintf(stderr, "open file error! \n");
		exit(-1);
	}
	int i = 0;
	typeAccount racct;
	while (fread(&racct, sizeof(racct), 1, fp)){

		if (strcmp(racct.name, acct.name) == 0 && 0 == strcmp(racct.passWd, acct.passWd))
		{

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

//chang account money 
void changeAccontMoney(){
	unsigned int money = 0;
	printf("Pleas input account name , account passwd, new account money ~!\n\n");
	typeAccount account;
	scanf("%s %s %u", &account.name, &account.passWd, &account.money);
	int flag = changeMoney(account); //change account money
	if (flag == -1){
		printf("Sorry, there is no this account ro your passwd error , check it ~! \n\n");
	}
	else{
		printf("The money changed..\n\n");
	}
}

// play games
/*
this games is guess the number which is a pseudo-random between 0 - 36; if you get it ,you will win 10$, if you faulure ,you will loss 10$, of course if you want to play the game , you must have more than $10;
*/
void playGame(){
	printf("Pleas input account name , account passwd:\n");
	typeAccount account;
	scanf("%s %s", &account.name, &account.passWd);
	int flag = findAccount(account);
	if (flag == -1){
		printf("Sorry, there is no this account or your passwd error , check it  and continue~! \n\n");
	}

	else{
		printf("    Ok, you will use the account named: %s to play the games~!\n", account.name);
		while (1){
			printf("\nFirst please bet , at odds of 37 to 1~~! \n");
			int odd = 1;
			scanf("%d", &odd);
			if (odd < 1){
				printf(" Sorry, your odds error, less than 1~~!　\n");
				continue;
			}
			if (flag < 37 * odd){ //there is no enough money to play ... return 
				printf("\nThis account has no enough money to play the games with odds %d ~@! \n", odd);
				continue;
			}
			else{
				printf("\nCongratulations， your account has enough money, $%d to play the games~! \n", flag);
			}
		RIN: printf("OK...Start the game ~~~~: \n"
			"     please  input a number  between 0 - 36~~!\n"
			"     such as: 1 \n"
			"     tip: input <0 will treminate the game !\n");
			 int guess = -1;
			 scanf("%d", &guess);
			 if (guess >= 37){
				 printf(" Sorry, input error ~, please input 0 - 36~!\n\n");
				 goto RIN;
			 }
			 if (guess < 0)
				 break;
			 int result = CreatRandNum();  //get the random number; 
			 if (result == guess) // get it , win
			 {
				 flag += 10 * odd;
				 printf(" \nOk, you win~~! \n"
					 "    result is  %d, your get it~;  now  your money is $%d \n", result, guess, flag);
			 }
			 else{  // faulure ;
				 flag -= odd;  // money loss $10
				 printf(" \nSorry, you Failure~~! \n");
				 printf("    result is  %d, but your input is %d; now your money is $%d \n", result, guess, flag);
			 }

		}
	}
	account.money = flag;
	changeMoney(account); //update the account money....

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
			"    2:start play the games~!\n"
			"    3:game over~! \n");
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
		else if (3 == mode){
			printf("Game over~! \n");
			exit(1);
		}

	}
	return 0;
}