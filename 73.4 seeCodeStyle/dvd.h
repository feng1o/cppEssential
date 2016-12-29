#ifndef DVD_H
#define DVD_H
#define MAX_SIZE 50 //the longest name is 50
enum AgeLimit // age limit info
{
	FOR_CHILDREN,
	NOT_FOR_CHILDREN,
	FOR_ADULT
};
enum Genre // the classification
{
	HORROR,
	ROMANCE,
	ACTION,
	DRAMA
};
enum RentalDurationType{ // charge mode
	DayType,
	MonType,
	QuarterType
};
typedef struct Dvd{
	char title[MAX_SIZE]; // movie title
	char actor[MAX_SIZE * 10]; //all actor/ress 's name are in this , split them with ,
	char director[MAX_SIZE];  // director
	int copies; //remain copies
} Dvd;

typedef struct Customer{
	int number; //customer number
	char name[MAX_SIZE];
	int age;
	char telephone[MAX_SIZE];
	char address[MAX_SIZE];
	double pendingCharges; // customer's pend charges
	char rentalHistory[MAX_SIZE * 20]; // rental history
	char rentalRestriction[MAX_SIZE];
	double penalties;
	int rentSize; // current rent nums
	char currRent[10][MAX_SIZE]; // the dvd customer rented, no more than 10
}Customer;

typedef struct System
{
	int sizeDvd;
	Dvd dvds[200];
	int sizeCus;
	Customer customers[100];
	enum RentalDurationType type;
	double feePerDay; //租赁每日费用
	double feePerMon;
	double feePerQuarter;
}System;

void addCopy();
void editCopy();
void deleteCopy();
void editDurationType();
void addCustomer();
void editCustomer();
void deleteCustomer();
void viewStatus();
void viewCustomer();
void customerRent();
void returnLoans();
#endif