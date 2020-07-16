#include <stdio.h>

int main(int argc, char** argv) {
    
    const int size = 5;
    int arr[size];       // Declare the array of integers
    
    // Fill the array with user input
    printf("Please enter %d numbers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Print the whole array
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calculate average, max and min
    int total = 0;
    int max = arr[0];  // Careful when initializing these!
    int min = arr[0];
    
    for (int i = 0; i < size; i++) {
        total += arr[i];     // Calculate total
        
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    double ave = (double)total/size;  // Calculate average, only once
    
    printf("\nThe average is %g\n", ave);
    printf("The maximum is %d and the minimum is %d\n", max, min);

}
