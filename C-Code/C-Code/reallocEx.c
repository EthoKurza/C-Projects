#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {   
	
	//const int size = 1000;
	int size = 1000;
    int* arr = malloc(size * sizeof(int));

    // Fill the array with numbers 1, 2, 3, 4, ...
    for (int i = 0; i < size; i++) {
        arr[i] = i+1;
        
    }
    
	//Enlarge the array to double it's size and fill with 999,998, 997,...,0
    //arr = realloc(arr, size*2);
    int count = size-1;
	size = size *2;
	printf("%p\n", (void*)arr);
    
    arr = realloc(arr, size*sizeof(int));
	printf("%p\n", (void*)arr);
    
	for (int i = size/2; i < size; i++) {
        arr[i] = count--;
        //printf("%d ", arr[i]);
        //count--;
    }
    
	// Print the contents of the array
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);

    }
    printf("\n");
    
    free(arr);  // Don't forget to deallocate memory
}
