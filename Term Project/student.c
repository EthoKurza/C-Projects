#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "clock.h"
#include "LinkedList.h"

/* PROG20799 Project, Prof. Georg Feil
   Student Name: Heyzzen Flores
   Student ID: 991 452 883    */

// Declare Student list
List* stdList;


// readFile function:
// Reads a CSV text file of students with four fields:
// Last name,first name,ID,GPA
// 'fileName' is the name of the text file to read.
// Returns the number of lines read, or -1 on errors.
// You may add a parameter to this function if you wish.
int readFile(const char fileName[]) {
	FILE *fptr;
	int lines = 0;

	if ((fptr = fopen(fileName, "r")) == NULL) {
		fprintf(stderr, "Error, failed to open %s: ", fileName);
		perror("");
		return -1;
	}

	char lastName[NAME_STR_LEN];
	char firstName[NAME_STR_LEN];
	long int ID;
	double GPA;
	while (feof(fptr) == 0) {
		// Read all fields from one line in the file into temporary variables
		// Assumes fields are separated by commas
		fscanf(fptr, "%99[^,],", lastName);
		fscanf(fptr, "%99[^,],", firstName);
		fscanf(fptr, "%ld,", &ID);
		fscanf(fptr, "%lf ", &GPA);

		//** Your code to create a node and append it to the linked list goes here

		// Add Studnets to list
		Node* std = createNode(lastName,firstName,ID,GPA);		// Create Student Node
		appendNode(stdList, std);

		lines++;
	}

	return lines;
}

int cmpfunc(const void* a, const void* b) {  // Integer comparison function
	double num1 = *(double*)a;
	double num2 = *(double*)b;

	if (num1 > num2) {
		return -1;
	} else if (num1 == num2) {
		return 0;
	} else {
		return 1;
	}
}

// Declare functions
void sortA(int n, double gpaArr[]);
void sortB(double gpaArr[], int n);




//=================== Main ==================//
int main(int argc, char** argv) {
	stdList = initList();	// Initialize List
	int lines = readFile("StudentListHalf.txt");

	printf("\n%d lines read from the file.\n", lines);

	//** Your code goes here **//
	// Declare variables
	clock_t start, end;
	double time;

	// Check if list is empty
	if(isEmpty(stdList)) {				// Exists program if list is empty
		printf("List is empty!\n");
		return 0;
	}

	// Fill array with gpa values
	double gpaArrA[lines], gpaArrB[lines];
	int count = 0;
	Node* temp = stdList->head;
	while (temp != NULL) {
		gpaArrA[count] = temp->GPA;			// Insert values for sortA
		gpaArrB[count] = temp->	GPA;		// Insert values for sortB
		temp = temp->next; // Go on to the next node
		count++;
	}


	// Sorting A

	start = clock();		// Get start time
	sortA(lines, gpaArrA);	// call Insertion Sort function
	end = clock();			// Get end time
	time = (double)(end - start) / CLOCKS_PER_SEC;		// Time taken in sec

	// Print first 50 GPA values from the sorted array 
	puts("====== Sorted Array A ======");
	for(int i = 0; i < 50; i++) {
		printf("%g\n",gpaArrA[i]);
	}
	
	printf("Sort A Time: %f seconds\n",time);

	// Sorting B

	start = clock();
	sortB(gpaArrB, lines);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;		// Time taken in sec
	
	// Print first 50 GPA values from the sorted array
	puts("====== Sorted Array B ======");
	for(int i = 0; i < 50; i++) {
		printf("%g\n",gpaArrB[i]);
	}
	printf("Sort B Time: %f seconds\n",time);


}// End of main

// Functions

void sortA(int n, double gpaArr[]) {
	double tempGPA;		// Create an array size of n
	int i, j;

	// Sort array
	for (i = 1; i < n; i++) {
		if (gpaArr[i] > gpaArr[i-1]) {
			tempGPA = gpaArr[i];
			for (j = i; j>0 && gpaArr[j-1]<tempGPA; j--) {
				gpaArr[j] = gpaArr[j-1];
			}
			gpaArr[j] = tempGPA;
		}
	}

}// end of sortA


void sortB(double gpaArr[], int n) {
	qsort(gpaArr, n , sizeof(double), cmpfunc);  // Sort the array
}// end of sortB


