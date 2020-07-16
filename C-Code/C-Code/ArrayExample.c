#include <stdio.h>
#include <stdbool.h>


int main(int argc, char** argv){

	/*	
	const int numValues = 30;
	int values[numValues];
	for(int index = 0; index < numValues; index++){
		values[index] = 999;
	}
	
	printf("The Last element is %d \n", values[-100]);
	*/
	
	/*
	-----------Exercise 1-------------
	*/
	
	const int arrSize = 5;
	int numbers[arrSize];
	int total=0,maxNum,minNum;
	
	//get integers from user
	printf("Enter 5 integers: ");
	for(int i =0; i<arrSize; i++){	//this reads only arrSize inputs from one line
		scanf("%d", &numbers[i]);
	}
	
	
	//calculate average, highest and lowest numbers
	maxNum = numbers[0];
	minNum = numbers[0];
	for(int i=0;i<arrSize; i++){
		//get the total of the array
		total+=numbers[i];
		
		//find highest number
		if(maxNum<numbers[i]){
			maxNum = numbers[i];
		}
		
		//find lowest number
		if(minNum>numbers[i]){
			minNum = numbers[i];
		}
	}

	//calculate average
	double avg = total / (double)arrSize;
	
	//print outputs
	printf("You've entered: ");
	for(int i=0;i<arrSize;i++){
		if((i+1)==arrSize){
			printf("%d \n ",numbers[i]);
		}
		else{
			printf("%d, ",numbers[i]);
		}
	
	}
	
	printf("The average is: %g \n",avg);		//%g removes 0s in the double output
	printf("The highest number is: %d\n",maxNum);
	printf("The lowest number is: %d\n",minNum);
	
	
	
	/*
	Example Passing an array parameter
	*/
	
	
	
	
	

	
}//end of main



