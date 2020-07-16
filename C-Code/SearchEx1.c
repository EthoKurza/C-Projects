#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int search(int arr[], int length, int num);

int main(int argc, char** argv){
	const int size = 6;
	int arr[] = { 90, 88, 56, 100, 2, 25};
	printf("Enter the number to search for: ");
	int num;
	scanf("%d", &num);
	
	int index = search(arr, size, num);
	if(index != -1){
		printf("Found %d at index %d.\n",num,index);
	}
	else{
		printf("Number not found\n");
	}
}


//search function
int search(int arr[], int length,int num){
	// Do a linear search for 'num'
	//bool found = false;	
	int index = -1;		// Where -1 means not found
	for(int i =0; i < length; i++){
		if(num == arr[i]){
			// Item Found
			//found = true;
			index = i;
			break;
		}
	}
	
	return index;
}


