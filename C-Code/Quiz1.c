#include <stdio.h>

int main(int argc, char** argv){
	
	//double piDouble = 3.14159265358979323846;
	//float piFloat = piDouble;
	
	//printf("Double: %.20f	\nFloat: %.20f \n",piDouble,piFloat);
	
	
	int fNum = 0, sNum = 0;
	
	printf("Enter First number: ");
	scanf("%d", &fNum);
	
	printf("Enter Second number: ");
	scanf("%d", &sNum);
	
	int sum = fNum+sNum;
	int quotient = fNum / sNum;
	int remainder = fNum % sNum;
	float fQuotient = (float)fNum / (float)sNum;
	
	printf("Sum: %d, Quotient: %d, Remainder: %d\n",sum,quotient,remainder);
	printf("Floating-point quotient: %f",fQuotient);
	
	
	return 0;
}
