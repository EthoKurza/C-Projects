#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// The array to sort
static int a[SIZE];

// Function prototypes
void HeapSort(int n);
void ReHeap(int len, int parent);
void swap(int* a, int* b);

int main(int argc, char** argv) {
	// Fill the array with random numbers
	for (int i = 0; i < SIZE; i++) {
		a[i] = rand();
	}
	
	// Sort
	HeapSort(SIZE);
	
	// Print the array contents
	for (int i = 0; i < SIZE; i++) {
		printf("%d\n", a[i]);
	}
}

// Heapsort implementation from the slides
void HeapSort(int n) {
    for (int i = n/2; i>= 0; i--)   // Step 2
        ReHeap(n, i);
    for (int i = n-1; i> 0; i--) {  // Step 3
        swap(&a[i], &a[0]);
        ReHeap(i, 0);
    }
}

// **Changed for descending order!
void ReHeap(int len, int parent) {
    int temp = a[parent];
    int child = 2*parent + 1;
    while (child < len) {
        if (child<len-1 && a[child]>a[child+1])
            child++;
        if (temp <= a[child])
            break;
        a[parent] = a[child];
        parent = child;
        child = 2*parent + 1;
    }
    a[parent] = temp;
}

// Swap the values of two variables
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

