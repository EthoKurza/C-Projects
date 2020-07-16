#include <stdio.h>
#include <stdbool.h>

int main(int argc, char** argv) {
	/*
	int num = 36;
	int* ptr = &num;			//best coding practice is to start pointers with a p

	//printf("Address of numPTR: %d\nAddress of num: %d\n",ptr,&num);		//same output, outputs address of num
	printf("num is: %d\n",num);
	printf("ptr is: %p\n",(void*)ptr);

	printf("ptr value is: %d\n", *ptr);


	//add 1
	num = num + 1;
	ptr = ptr + 1;

	printf("After adding 1, num is: %\n",num);
	printf("ptr is: %p\n",(void*)ptr);
	*/


	/*		Exercise 2 		*/
	/*
	int num = 36;
	int* ptr = &num;			//best coding practice is to start pointers with a p


	printf("printing num using a pointer is: %d\n", *ptr);



	//Add 1 to num using ptr
	printf("After adding 1, ptr is: %d\n", (*ptr+1));
	printf("Using pointer knowledge: %d\n", *(&num));			//datatype of a &num is a pointer to int


	//calculate num^2
	*ptr = *ptr * *ptr;
	printf("num^2 is: %d",*ptr);
	*/

	/*		Exercise 4		*/
	int count = 10;
	int* temp;
	int sum = 0;
	temp = &count;
	*temp = 20;
	temp = &sum;
	*temp = count;
	printf("count = %d, *temp = %d, sum = %d, temp[0] = %d\n",count, *temp, sum, temp[0]);



}//end of main
