#include <stdio.h>

double ave(int arr[], int len){
	int total = 0;
	for(int index=0;index<len;index++){
		total += arr[index];
	}
	return total / (double) len;
}

int main(int argc, char** argv){
	int numbers[] = {29,5,-7,101,-555}; //initialize array
	int len =5;
	
	//call function to calculate average and print it
	printf("The average is %g \n", ave(numbers,len));
}//end of main
