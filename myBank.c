
#include <stdio.h>
#include "myBank.h"
#define NUM_OF_ACCOUNTS 50
int current = 0 ;
double bankAccount[50][2] = {0} ;
char ci;
//function that prints the menu and get input from the user
char printMenu(){

	printf("\n");

	printf(" Please choose a transaction type:\n ");

	printf( "O-Open Account\n");

	printf(" B-Balance Inquiry\n");

	printf(" D-Deposit\n");

	printf(" W-Withdrawal\n");

	printf(" C-Close Account\n");

	printf(" I-Interest\n");

	printf(" P-Print\n");

	printf(" E-Exit\n");

	scanf(" %c", &ci);

	return ci ;

}


//open bank account if there is empty accounts 
//check before the deposit amount , if invalid send error messege and dont open account 
void openBankAccount() {

	for (int i = 0 ; i < NUM_OF_ACCOUNTS ; i++){

		if(bankAccount[i][0] != 1 ) {

			bankAccount[i][0] = 1 ;

			printf(" Please enter amount for deposit: ");

			printf("New account number is:  %d" , i+901);

			double c = 0 ;

			if(scanf("%lf",&c)==1){

				add(c,i);

				return;

			}else{

				printf("Failed to read the amount ");


				bankAccount[i][0] = 0 ;


				while(getchar()!='\n');

				return ;

			}

		}


		if(i == 49 ){

			printf(" Sorry we are full , please check in other banks /n");

			return;

		}


		
	
	}
}

//check the balance of the account , if get invalid account number send error messege

void checkBalance (int numOfBankAccount){

	if(numOfBankAccount < 0){

		printf("Invalid account number");

		return ;

	}


	if(numOfBankAccount<901 || numOfBankAccount>950){

		printf("Invalid account number");

	}

	if(bankAccount[numOfBankAccount-901][0] !=1){

		printf("This account is closed") ;


		

	}else{

		printf(" The balance of account number %d is: %.2lf", numOfBankAccount,bankAccount[numOfBankAccount-901][1]);


		
	}


}




//after open account send to add the deposite
//if the amount is invalid close the account
double add (double c ,int i ){


	if(c < 0 ){

		printf(" Invalid Amount");

		bankAccount[i][0] =0 ;

		return 0  ;

	}

	bankAccount[i][1] += c;



	
	return bankAccount[i][1];

}

//get withdraw , if account or amount invalid send error messege
void withdraw(int numOfBank , double howMuch){

	if(howMuch <0 ){

		printf("Invalid Amount");


		return;

	}

	if(bankAccount[numOfBank-901][0] != 1 ){


		printf("No such account");

		return ;

	}


	if(bankAccount[numOfBank - 901][1] < howMuch){

		printf(" Cannot withdraw more than the balance");


		return ;

	}


	double m = 0 ;


	m = decrease (numOfBank , howMuch);


	printf(" The new balance is: %.2lf" ,m);

}




//affter gettig withdraw decrease it from the account 

double decrease (int numOfBank , double howMuch){

	bankAccount[numOfBank-901 ][1] -= howMuch;

	return bankAccount[numOfBank-901][1];


}

void deposit(int numOfBank , double howMuch){

	if(bankAccount[numOfBank-901][0] != 1){


		printf(" No such account ,please open account first");


		return ;

	}


	if(howMuch < 0 ){

		printf(" Cannot deposit a negative amount");

		return;

	}

	printf("howMuch %lf", howMuch);

	bankAccount[numOfBank-901][1] += howMuch;

	printf(" The new balance is: %.2lf", bankAccount[numOfBank-901][1]);

}


//close account , if account is already closed or invalid send error messege
void closeAccount(int numOfBank){

	if(bankAccount[numOfBank-901][0] != 1){

		printf(" This account is already closed");

		return ;

	}


	bankAccount[numOfBank-901][0]=0;

	printf(" Closed account number %d", numOfBank);





}



//change the rate to all  accounts . if invalid send error messege

void interest(double value){


	if(value < 0){

		printf("Invalid interest rate");

	}

	for(int i = 0 ; i < NUM_OF_ACCOUNTS ; i++){

		if(bankAccount[i][0]==1){

			bankAccount[i][1] *= (1+value/100);


		}

	}

}
//print all the exist accounts 
void printAll(){

	for(int i = 0; i < NUM_OF_ACCOUNTS; i++){


		if(bankAccount[i][0] == 1 ){

			printf("The balance of account number %d is: %.2lf \n" , 901+i , bankAccount[i][1]);}

	}

}

