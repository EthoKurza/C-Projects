#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int binarySearch(int arr[], int n, int value);
int compar(const void* a,const void* b);

int main(int argc, char** argv){
	int arr[SIZE];
	
	// Generate and fill array with random integers
	srand(42);	// Initialize random number generator, do this only once
	for(int i=0; i < SIZE; i++){
		arr[i] = rand();
	}	

	// sort array
	qsort(arr,SIZE,sizeof(arr[0]),compar);
	
	// Search array
	int step1000 = binarySearch(arr,SIZE,18718);
	
	if(step1000 != -1){
		printf("It took %d steps to find 18718",step1000);
	}
	else{
		printf("Number 18718 was not found");
	}
	
	
}

// Functions
int compar(const void* a,const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if(num1 < num2) {
		return -1;
	} else if( num1 == num2) {
		return 0;
	} 
	else {
		return 1;
	}

}

int binarySearch(int arr[], int n, int value) {
	int first = 0, last = n-1, index = -1, numSteps = 0;
	while (first <= last) {
		int middle = (first + last) / 2;  // Pick the middle index
		if (arr[middle] == value) {
			//index = middle;      // We found the value!
			index = numSteps;		// return number of total steps
			break;
		} else if (arr[middle] > value) {
			last = middle -1;   // Adjust interval end point
		} else {
			first = middle + 1;  // Adjust interval start point
		}
		numSteps++;
	}
	return index;  // Return index of value, -1 means not found
}

