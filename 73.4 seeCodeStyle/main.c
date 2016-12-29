#include "dvd.h"



int main()
{
	char * menu1 = "\t\t=================================================\n\
		\tBranch Manager menu \n\
		1. add copies \n\
		2. edit copies\n\
		3. delete copies\n\
		4. alter rental duration type and alter charges\n\
		5. add customer\n\
		6. edit customer\n\
		7. remove customer\n\
		8. View current stock status\n\
		9. View customer info\n\
		=================================================\n\n";
	char * menu2 = "\t\t=================================================\n\
		1. add customer\n\
		2. edit customer \n\
		3. delete customer \n\
		=================================================\n\n";
	char * menu3 = "\t\t=================================================\n\
				   \txxxx\n\
		\tRental desk worker \n\
		1. rent dvd \n\
		2. return dvd\n\
		=================================================\n\n";
	char * menu = "\t\t=================================================\n\
				  xxxx\n\
		\tPlease enter your rank: \n\
		xxxxxxxx....\n\
		1 .Branch Manager \n\
		3333.\n\
		2. Registration desk worker \n\
		3. Rental desk worker \n\
		=================================================\n\n";
	int c = 0;
	int cont = 1;
	while (1){
		printf("%s", menu);
		scanf("%d", &c);
		if (c == 1){
			cont = 1;
			while (cont)
			{
				printf("%s", menu1);
				scanf("%d", &c);
				switch (c)
				{
				case 1:
					addCopy();
					break;
				case 2:
					editCopy();
					break;
				case 3:
					deleteCopy();
					break;
				case 4:
					editDurationType();
					break;
				case 5:
					addCustomer();
					break;
				case 6:
					editCustomer();
					break;
				case 7:
					deleteCustomer();
					break;
				case 8:
					viewStatus();
					break;
				case 9:
					viewCustomer();
					break;
				default:
					cont = 0;
					break;
				}
			}
		}
		else if (c == 2){
			printf("%s", menu2);
			scanf("%d", &c);
			if (c == 1){
				addCustomer();
			}
			else if (c == 2){
				editCustomer();
			}
			else if (c == 3){
				deleteCustomer();
			}
			else{

			}
		}
		else if (c == 3){
			printf("%s", menu3);
			scanf("%d", &c);
			if (c == 1){
				customerRent();
			}
			else if (c == 2)
			{
				returnLoans();
			}
		}
		else
		{
			break;
		}
	}
}