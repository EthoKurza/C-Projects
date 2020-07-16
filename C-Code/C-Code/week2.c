#include <stdio.h>
#include <stdbool.h>


static double Radius = 0.25;
int main(int argc, char** argv){
	//printf("\nAn int is %d bytes \n",(int)sizeof(int));
	
	/**	
		Exercise 1 - Week 2
	*/
	
	int sum;
	bool isCorrect = true;
	char grade = 'A';
	short int age = 100;
	short age2;						//same as short int
	//double Radius = 0.25;
	float average;
	unsigned int register_sp;
	unsigned char byte;		
	long int big;
	long big35var;						//same as long int
	long long int reallyBig = 10928094830104892;
	signed int justLikeInt;				//same as int
	
	//theres also:
	unsigned long int uns_num1;
	unsigned long long int uns_num2;
	unsigned short int s_num; 
	
	
	printf("grade is %c, age is %d\n",grade,age);
	printf("grade is %d, age is %d\n",grade,age);	//grade will print out based on ascii table
	
	//printing booleans
	printf("isCorrect is ");
	if(isCorrect)
		printf("true \n");
	else
		printf("false \n");
		
		
	//printing a long long int
	printf("reallyBig is %lld \n", reallyBig);
	
	//printing doubles
	printf("Radius %g or %lf \n", Radius, Radius);
	
	
	
	
	return 0;
}
