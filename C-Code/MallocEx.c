#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
	char name[100];
	int id;
	double GPA;
} Student;

int main(int argc, char** argv){
	
	//printf("size of student %d", sizeof(Student));			//will be 112 because char is 1 byte and its in an array of size 100, plus int(4 bytes), plus double(8 bytes)
	
	
	
	/**		Malloc Exercise		*/
	const int size = 1000;
	int* arr = malloc(size * sizeof(int));
	
	for(int i =0; i < size; i++){
		arr[i] = i;
	}
	
	for(int i =0; i < size; i++){
		printf("%d\n", arr[i]);
	}
	
	free(arr);
	
	
}//end of main
