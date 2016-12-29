#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "dvd.h"

System sys;

/*add a dvd copy to the system*/
void addCopy()
{
	printf("Enter DVD title: ");
	fflush(stdin);
	gets(sys.dvds[sys.sizeDvd].title);
	fflush(stdin);
	printf("Enter copies: ");
	scanf("%d", &sys.dvds[sys.sizeDvd].copies);
	printf("Enter the director: ");
	scanf("%s", sys.dvds[sys.sizeDvd].director);
	fflush(stdin);
	printf("Enter all actors: ");
	scanf("%s", sys.dvds[sys.sizeDvd].actor);
	fflush(stdin);
	sys.sizeDvd++;
	printf("Finished!\n\n");
}

/*edit the movie copy*/
void editCopy()
{
	char title[MAX_SIZE];
	int i = 0;
	printf("Enter DVD title to edit: ");
	fflush(stdin);
	gets(title);
	fflush(stdin);
	for (i = 0; i < sys.sizeDvd; ++i){ //find the copy
		if (strcmp(title, sys.dvds[i].title) == 0)
			break;
	}
	if (i == sys.sizeDvd){ // can't find the copy
		printf("No found!\n");
		return 0;
	}
	printf("Enter new DVD title: "); // revise the info
	scanf("%s", sys.dvds[i].title);
	fflush(stdin);
	printf("Enter new copies: ");
	scanf("%d", &sys.dvds[i].copies);
	printf("Enter the new director: ");
	scanf("%s", sys.dvds[i].director);
	fflush(stdin);
	printf("Enter new actors: ");
	scanf("%s", sys.dvds[i].actor);
	fflush(stdin);
	printf("Finished!\n\n");
}

/*delete the copy from the system*/
void deleteCopy()
{
	char title[MAX_SIZE];
	int i = 0;
	printf("Enter DVD title to delete: ");
	scanf("%s", title);
	for (i = 0; i < sys.sizeDvd; ++i){ // find the copy
		if (strcmp(title, sys.dvds[i].title) == 0)
			break;
	}
	if (i == sys.sizeDvd){
		printf("No found!\n");
		return 0;
	}
	memmove(&sys.dvds[i], &sys.dvds[i + 1], (sys.sizeDvd - i - 1) * sizeof(Dvd)); // delete it
	sys.sizeDvd--;
	printf("Finished!\n\n");
}

/*edit the charge cycle*/
void editDurationType()
{
	int chioce;
	printf("Choose rental duration type (1. day, 2. month, 3. quarter ): ");
	scanf("%d", &chioce);
	if (chioce == 1){ // cal charge by day
		sys.type = DayType;
		printf("Enter fees per day: ");
		scanf("%lf", &sys.feePerDay);
	}
	else if (chioce == 1){ // cal charge by mon
		sys.type = MonType;
		printf("Enter fees per month: ");
		scanf("%lf", &sys.feePerMon);
	}
	else // cal charge by quarter
	{
		sys.type = QuarterType;
		printf("Enter fees per quarter: ");
		scanf("%lf", &sys.feePerQuarter);
	}
	printf("Finished!\n\n");
}

/*add a customer to the system*/
void addCustomer()
{
	int pos = sys.sizeCus;
	printf("Enter customer number: ");
	scanf("%d", &sys.customers[pos].number);
	printf("Enter name: ");
	scanf("%s", sys.customers[pos].name);
	fflush(stdin);
	printf("Enter the age: ");
	scanf("%d", &sys.customers[pos].age);
	printf("Enter the telephone number: ");
	scanf("%s", sys.customers[pos].telephone);
	fflush(stdin);
	printf("Enter the address: ");
	scanf("%s", sys.customers[pos].address);
	fflush(stdin);
	printf("Enter pending charges: ");
	scanf("%lf", &sys.customers[pos].pendingCharges);
	printf("Enter rental history: ");
	scanf("%s", sys.customers[pos].rentalHistory);
	fflush(stdin);
	printf("Enter rental restriction: ");
	scanf("%s", sys.customers[pos].rentalRestriction);
	fflush(stdin);
	printf("Enter rental penalties: ");
	scanf("%lf", &sys.customers[pos].penalties);
	fflush(stdin);
	sys.sizeCus++;
	printf("Finished!\n\n");
}


/*edit the customer information*/
void editCustomer()
{
	int id = 0;
	int pos = 0;
	printf("Enter customer id: ");
	scanf("%d", &id);
	for (pos = 0; pos < sys.sizeCus; ++pos){ /*find the customer*/
		if (id == sys.customers[pos].number)
			break;
	}
	if (pos == sys.sizeCus){
		printf("No found!\n");
		return;
	}
	/*change the info*/
	printf("Enter new customer number: ");
	scanf("%d", &sys.customers[pos].number);
	printf("Enter new name: ");
	scanf("%s", sys.customers[pos].name);
	fflush(stdin);
	printf("Enter new age: ");
	scanf("%d", &sys.customers[pos].age);
	printf("Enter new telephone number: ");
	scanf("%s", sys.customers[pos].telephone);
	fflush(stdin);
	printf("Enter new address: ");
	scanf("%s", sys.customers[pos].address);
	fflush(stdin);
	printf("Enter new pending charges: ");
	scanf("%lf", &sys.customers[pos].pendingCharges);
	printf("Enter new rental history: ");
	scanf("%s", sys.customers[pos].rentalHistory);
	fflush(stdin);
	printf("Enter new rental restriction: ");
	scanf("%s", sys.customers[pos].rentalRestriction);
	fflush(stdin);
	printf("Enter new rental penalties: ");
	scanf("%lf", &sys.customers[pos].penalties);
	fflush(stdin);
	printf("Finished!\n\n");
}

/*delete customer from the system*/
void deleteCustomer()
{
	int id = 0;
	int i = 0;
	printf("Enter customer id: ");
	scanf("%d", &id);
	/*find the target customer*/
	for (i = 0; i < sys.sizeCus; ++i){
		if (id == sys.customers[i].number)
			break;
	}
	if (i == sys.sizeCus){
		printf("No found!\n");
		return;
	}
	memmove(&sys.customers[i], &sys.customers[i + 1], (sys.sizeCus - i - 1) * sizeof(Customer));
	sys.sizeCus--;
	printf("Finished!\n\n");
}

/*view the dvd stock information*/
void viewStatus(){
	int i = 0;
	printf("All stock status : \n");
	for (i = 0; i < sys.sizeDvd; ++i){
		printf("%d. %s, remain copies: %d. \n", i + 1, sys.dvds[i].title, sys.dvds[i].copies);
	}
	printf("Finished!\n\n");
}

/*view all customer information*/
void viewCustomer(){
	int i = 0;
	printf("All customer status: \n");
	for (int i = 0; i < sys.sizeCus; ++i){
		printf("%d. Number: %04d, Name: %s, Age: %d, Tel: %s, Addr: %s.\n", i + 1,
			sys.customers[i].number, sys.customers[i].name, sys.customers[i].age,
			sys.customers[i].telephone, sys.customers[i].address);
	}
	printf("Finished!\n\n");
}

/*customer rent a book*/
void customerRent()
{
	int id = 0, i = 0;
	char title[MAX_SIZE];
	printf("Enter customer number: ");
	scanf("%d", &id);
	for (i = 0; i < sys.sizeCus; ++i){ // find the target customer
		if (id == sys.customers[i].number)
			break;
	}
	if (i == sys.sizeCus){
		printf("No found!\n");
		return;
	}
	id = i;
	printf("Enter the dvd title the customer want to rent: ");
	scanf("%s", title);
	fflush(stdin);

	for (i = 0; i < sys.sizeDvd; ++i){ // rent a book
		if (strcmp(title, sys.dvds[i].title) == 0)
			break;
	}
	if (i == sys.sizeDvd){
		printf("No found!\n");
		return 0;
	}
	if (sys.dvds[i].copies <= 0){ // no more copies, return
		printf("No more copies !\n");
		return;
	}
	sys.dvds[i].copies--;
	strcpy(sys.customers[id].currRent[sys.customers[id].rentSize++], title);
	printf("Enter the charges the customer have to pay: ");
	scanf("%lf", &sys.customers[id].pendingCharges);
	printf("Finished!\n\n");
	return;
}

/*customer return a book*/
void returnLoans()
{
	int id = 0, i = 0, chioce = 0, j = 0;
	double p = 0.0;
	char title[MAX_SIZE];
	printf("Enter customer number: ");
	scanf("%d", &id);
	for (i = 0; i < sys.sizeCus; ++i){ /*find the target customer*/
		if (id == sys.customers[i].number)
			break;
	}
	if (i == sys.sizeCus){
		printf("No found!\n");
		return;
	}
	id = i;
	/*show all dvd the customer rented, and choose the one to return*/
	printf("The Customer rent the below dvds, enter number to return: ");
	for (i = 0; i < sys.customers[id].rentSize; ++i){
		printf("%d. %s\n", i + 1, sys.customers[id].currRent[i]);
	}
	scanf("%d", &chioce);

	for (j = 0; j < sys.sizeDvd; ++j){ //find the copy
		if (strcmp(sys.customers[id].currRent[chioce - 1], sys.dvds[j].title) == 0){
			sys.dvds[j].copies += 1;// return a copy, so the count increase
			break;
		}
	}

	memmove(&sys.customers[id].currRent[chioce - 1], &sys.customers[id].currRent[chioce], sizeof(char) * 10 * (10 - chioce)); //return a dvd
	printf("Enter the penalties the customer have to pay: ");
	scanf("%lf", &p);
	sys.customers[id].penalties += p; //Add current parts of penalty to the user's total penalty
	sys.customers[id].rentSize--; // sub the user's current rent number
}

