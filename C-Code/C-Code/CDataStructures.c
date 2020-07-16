#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef unsigned int uint;
typedef unsigned short int usint;
typedef unsigned char uchar;

//make a constant
#define NUM_ST 3

typedef struct{
//struct student{
	char name[50];
	int id;
	double GPA;
}Student;
//};

void printStudent(Student st);

int main(int argc, char** argv){
	//Create a variable of the student structure type
	
	//struct Student myStudent;			//struct is a datatype

	
	//Input values for all three fields from the user
//	printf("Enter Name, ID, GPA: ");
//	scanf("%s%d%lf", myStudent.name, &myStudent.id, &myStudent.GPA);
	//scanf("%s", myStudent.name);
	//scanf("%d", myStudent.id);
	//scanf("%f", myStudent.GPA);
	
	//Print the values of all three fields
//	printf("\nName: %s\nID: %d\nGPA: %.1f",myStudent.name,myStudent.id,myStudent.GPA);
	
	///////////////////////////////////////////////////////////////////////////////////
	
	//Type Def
//	uint num1=3;
//	usint snum=32767;
//	uchar ch = 255;		//255 is the bigges unsigned char
	
//	printf("The size of num1 is: %d\n", sizeof(num1));	
//	printf("The size of snum is: %d\n", sizeof(snum));
//	printf("The size of ch is: %d\n", sizeof(ch));
	
	////////////////////////////////////////////////////////////////////////////////////
	//Input values for all three fields from the user
//	Student myStudent;					//Student is a typeDef of a struct(typeDef is basically making an alias of that struct)
	
//	printf("Enter Name, ID, GPA: ");
//	scanf("%s%d%lf", myStudent.name, &myStudent.id, &myStudent.GPA);

	
	//Print the values of all three fields
//	printStudent(myStudent);



	//////////////////////////////////////////////////////////////////////////////////////
	Student stArr[NUM_ST];
	
	for(int i =0; i<NUM_ST;i++){
		printf("Enter Name, ID, GPA for student %d: ",i);
		scanf("%s%d%lf", stArr[i].name, &stArr[i].id, &stArr[i].GPA);
	}
	
	for(int i=0; i<NUM_ST; i++){
			printStudent(stArr[i]);
	}

	
	
	
}//end of main



void printStudent(Student st){
		printf("\nName: %s\nID: %d\nGPA: %.1f",st.name,st.id,st.GPA);
}
