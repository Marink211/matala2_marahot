#include <stdio.h>
#include "myBank.h"

int main(){
	double howMuch = 0 ;
	int account =0 ;
	char c;
	c=printMenu();
//switch casese according to the input
	switch (c){
		      
	      	while(getchar()!='\n');
//make while didnt get exist
	
		while(c!='E'){
		
			case 'O' : openBankAccount();
				   main();
				   break;
			case 'B' : printf("Please enter account number: ");
			   int ci=0;
//check if the input is valid		
			   if(scanf("%d",&ci)== 1){
					   checkBalance (ci);
				   }else{
					   printf("Faild to read the account number");
				   }
				   main();
				   break;

			case 'W' : printf("Please enter account number: ");
				   if(scanf("%d",&account)== 1){
					   printf(" Please enter the amount to withdraw: ");
					   if(scanf("%lf",&howMuch)==1){
						   withdraw(account,howMuch);
						  
					   }else{                                                      
						   printf("Faild to read the amount ");

					   }
				   }else{
				
					   printf("Faild to read the account number");
				   }

				   main();
				   break ;
			case 'D' : printf("Please enter account number ");
				   if(scanf("%d",&account)==1){
					   if(account < 0 ){
						   printf("Invalid account number");

					   }else{
						   printf(" Please enter the amount to deposit: ");
						   if(scanf("%lf", &howMuch)==1){
							   deposit(account,howMuch);
						   }else{
							   printf("Faild to read deposit");
						   }}
				   }else{
					   printf(" Failed to read the account number");
				   }				   
				   main();
				   break;
			case 'C' : printf(" please enter account number: ");
				   if(scanf("%d" ,&account)==1){
					   closeAccount(account);
				   }else{
					   printf("Failed to read account number");
				   }
				   main();
				   break;
			case 'I' : printf("Please enter interest rate: ");
				   double value= 0;
				   if(scanf("%lf",&value)==1){
					   interest(value);

				   }else{
					   printf("Faild to read the interest rate");
				   }
				   main();
				   break;
			case 'P' : printAll();
				   main();
				   break;
		}
		case 'E' : break;
		default :
			   printf(" Invalid Amount \n");
			   main();

	}
	
	return 0;
}



