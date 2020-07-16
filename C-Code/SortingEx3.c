#include <stdio.h>
#include <stdlib.h>

// This is our comparison function to be used to sort an array of doubles
// in ascending order (we'll change it to descending order next class).
// Note we can't use the subtraction trick as we can for integers. One example
// of why: Imagine we're comparing 1.4 to 1.3, a - b would be 0.1 which becomes
// zero when converted to an int, but 1.4 and 1.3 are not the same.
int cmpfunc(const void* a, const void* b) {  // Integer comparison function
    double num1 = *(double*)a;
    double num2 = *(double*)b;
    
    if (num1 < num2) {
    	return -1;
	}
	else if (num1 == num2) {
		return 0;
	}
	else {
		return 1;
	}
}

int main(int argc, char** argv) {
    const int size = 5;               // # items in the array
    double values[size];

    // Input numbers from the user
    printf("Please enter %d floating-point numbers: ", size);
    for (int i = 0 ; i < size; i++) {
        scanf("%lf", &values[i]);
    }

	// Sort using the qsort library function
    qsort(values, size, sizeof(double), cmpfunc);  // Sort the array "in place"

	// Print the numbers
    printf("\nAfter sorting the list is: \n");
    for (int i = 0 ; i < size; i++) {   
        printf("%g ", values[i]);
    }
  
    return 0;
}

