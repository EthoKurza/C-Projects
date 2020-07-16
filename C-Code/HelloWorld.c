#include <stdio.h>
// The Mathematical constant Pi ( we will calculate it.)
// This is a global variable.
double Pi;

/* Hello World Program */

int main(int argc, char** argv){
	/*========== Exercise 1 ==========*/
	printf("Hello World \n");
	printf("Hello, my name is Heyzzen Flores. \n");
	printf("I Hope this C program works!");
	
	/* ======== Exercise 2 ==========*/
	puts("\nThis is a for loop!");
	for(int i =1; i <=3 ; i++){
		//printf("Heyzzen's 'loop: %d",i);			//runs program faster
		printf("Heyzzen's 'loop: %d \n",i);
	}
	
		
	/*========== Example 1 =========*/
	printf("Hello this is the Pi Program\n");
	
	Pi   = 355.0 / 113.0;					//was declared before main as a global variable
	printf("Pi is about %f\n", Pi);
	
	// Input how much to multiply by (this is a local variable)   
	double multiplier = 0;
	printf("Please enter how much to multiply Pi  by\n");
	scanf("%lf", &multiplier);
	
	double manyPi = multiplier * Pi;
	printf("Pi multiplied by %f is %f\n", multiplier, manyPi);
	
	/*========== Example 1 Extended =========*/
	printf("Hello this is the Pi Program\n");
	
	Pi   = 355.0 / 113.0;					//was declared before main as a global variable
	printf("Pi is about %f\n", Pi);
	
	// Input how much to multiply by (this is a local variable)   
	multiplier = 0;
	//check if value grabbed fron user is valid
	int checkScan = 0;

		printf("Please enter how much to multiply Pi  by\n");
		checkScan = scanf("%lf", &multiplier);
		if(checkScan !=1){
			printf("Error input invalid! \n");
			return 0;					//exits main
		}
		manyPi = multiplier * Pi;
		printf("Pi multiplied by %f is %f\n", multiplier, manyPi);
	
	
	
}
