#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int search(int arr[], int length, int num);
int binarySearch(int arr[], int n, int value);

// acending sort
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

int main(int argc, char** argv) {
	const int size = 6;
	int arr[] = { 90, 88, 56, 100, 2, 25};
	printf("Enter the number to search for: ");
	int num;
	scanf("%d", &num);

	//int index = search(arr, size, num);

	// Sort the array
	qsort(arr, size, sizeof(arr[0]),compar);

	int index = binarySearch(arr,size ,num);
	if(index != -1) {
		printf("Found %d at index %d.\n",num,index);
	} else {
		printf("Number not found\n");
	}
}


//search function
int search(int arr[], int length,int num) {
	// Do a linear search for 'num'
	//bool found = false;
	int index = -1;		// Where -1 means not found
	for(int i =0; i < length; i++) {
		if(num == arr[i]) {
			// Item Found
			//found = true;
			index = i;
			break;
		}
	}

	return index;
}

int binarySearch(int arr[], int n, int value) {
	int first = 0, last = n-1, index = -1;
	while (first <= last) {
		int middle = (first + last) / 2;  // Pick the middle index
		if (arr[middle] == value) {
			index = middle;      // We found the value!
			break;
		} else if (arr[middle] > value) {
			last = middle -1;   // Adjust interval end point
		} else {
			first = middle + 1;  // Adjust interval start point
		}
	}
	return index;  // Return index of value, -1 means not found
}


