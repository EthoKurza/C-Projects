#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void increment(int num);
void increment2(int* num);
void powers(double num, double* square, double* cube);		//called function prototype (its a function declaration)
int myStrLen(char* str);

int main(int argc, char** argv) {
	/*		Exercise 1		*/
	/*
	int num = 0;
	printf("Original num: %d\n",num);

	increment(num);
	printf("increment 1: %d\n",num);		//the value inside the function is forever lost
	//the one above doesnt work because it creates a copy of the variable that its passing which means that it increments the copy and not the original variable

	increment2(&num);
	printf("increment 2: %d\n",num);		//this points to the data
	//this works because we are passing the variable itself to the function and it will increment that variable

	*/

	/*		Exercise 2		*/
	/*
	double num1, num2;

	powers(10.2,&num1,&num2);

	printf("Results: \nsquare: %g \ncube: %g",num1, num2);
	*/

	/*		Pointer Arithmatic Example		*/
/*	char str[100] = "Today is the day!";			//an array is a pointer to its first element
	char* pos = str;								//points to the very first letter
	
	while (*pos != '\0') {
		printf("%c   %p\n", *pos, pos);
		pos++;
	}
	
	*/
	
	/*
	//			Exercise 3			
	puts("\n====== Exercise 3 =======\n");
	char str[100];
	printf("Enter a string: ");
	scanf("%s",str);
	int backCount= strlen(str) - 1;
	//int backCount = len-1;
	
	char* forward = str;
	char* backward = str + backCount;
	
	//print string forwards and backwards
	while(*forward != '\0'){
		printf("%c 		%c\n\n",  *forward, *backward);
		forward++;
		backward--;
	}
		
	//			Exercise 4			
	puts("\n====== Exercise 4 ======\n");
	int nums[] = {87, -5, 33, 2, -9};
	int* pos = nums;
	const int len = 5;
	
	//print the array using pointers
	for(int i = 0; i < len ; i++){	
		printf("%p	%d\n",(void*)pos, *pos);		//pointer address increments by 4 because the array is of type int which uses 4 bytes to store
		pos++;
	}
	*/
	
	
	

	
	//			Exercise 5			
	char str[100];
	puts("\n====== Exercise 5 ======\n");
	printf("Enter a new String: ");
	scanf("%s",str);
	
	//get length
	int myLen = myStrLen(str);
	int sLen = strlen(str);
	
	//print results
	printf("\n\nmyStrLen: %d\nstrlen: %d",myLen, sLen);
	
	
	
	
}//end of main

/*		Exercise 5		*/
int myStrLen(char* str){
	char* pos =str;
	int len =0;
	//more efficient way
	//while(pos[len] != '\0'){
	while(*pos != '\0'){
		len++;			//length counter
		str++;			//go to the next part of the array
	}
	return len;
}



//methods
/*		Exercise 1		*/
void increment(int num) {		//call by value
	num = num + 1;
}

void increment2(int* num) {		//call by reference
	*num =  *num + 1;
}

/* 		Exercise 2		*/
void powers(double num, double* square, double* cube) {

	*square = num * num;
	*cube = *square * num;
}



