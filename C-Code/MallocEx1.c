#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    
    // Dynamically allocate an array of integers/doubles
    const int size = 1000;
    //int* arr = malloc(size * sizeof(int));
    
    //double* arr = malloc(size * sizeof(double));
    
    //calloc
    //double* arr = calloc(size, sizeof(double));
    
    //realloc
    int* arr = malloc(size, sizeof(int));

    // Fill the array with numbers 0, 1, 2, 3, ...
    for (int i = 0; i < size; i++) {
        arr[i] = i;
        
		arr[i] = i+1;		//will start from 1 and end at 1000
       
	   //arr[i] = (i + 1) / 10.0; //go by doubles
    }

	

    // Print the contents of the array
    for (int i = 0; i < size; i++) {
        printf("%g ", arr[i]);
    }
    printf("\n");
    
    free(arr);  // Don't forget to deallocate memory
}
