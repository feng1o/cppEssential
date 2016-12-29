/*
*/
#define _CRT_SECURE_NO_WARNINGS
#include "head.h"

#define  LIMIT 30
int main(){
	char* toolBar = "\t\t*****************************************\n"
		"\t\t	choose your status : \n"
		"\t\t0. Branch manager\n"
		"\t\t1. Registration Desk Worker \n"
		"\t\t2. Rental Desk Worker\n"
		"\t\t-1. exit\n"
		"\t\t*****************************************\n\n";
	while (1){
		printf("%s", toolBar);
		int n = -1;
		scanf("%d", &n);
		printf("\n");
		if (n == 0)
		{
			BranchManagerDo(0);
		}
		else if (n == 1){
			RegistWorkerDo(0);
		}
		else if (n == 2){
			RentWorkerDo(0);
		}
		else if (n == -1){
			printf("exit....~!\n");
			break;
		}
	}
	return 0;
}
