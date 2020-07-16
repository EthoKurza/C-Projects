#include <stdio.h>
#include <stdbool.h>


typedef struct {
	char first[21];
	char middle;
	char last[21];
}  Name;
typedef struct {
	int day;
	int month;
	int year;
}  Date;

typedef struct {
	Name name;
	int id;
	double GPA;
} Student;

//declare functions
//Input all fields of output parameter 'pSt'
void inputStudent(Student* pSt){
	// input all three fields of 'st'
		printf("Please enter the student First Name, Middle Name, Last Name, ID, and GPA for student: ");
		scanf("%s %c %s %d %lf", pSt->name.first, &pSt->name.middle, pSt->name.last, &pSt->id, &pSt->GPA);
	
}//end of inputStudent


// Print the fields of a student structure
void printStudent(const Student* st) {
    printf("Student's name: %s %c %s\n", st->name.first, st->name.middle, st->name.last);
    printf("Student ID: %d\n", st->id);
    printf("Student's GPA: %f\n", st->GPA);    
}

int main(int argc, char** argv) {
    Student st;
    
	inputStudent(&st);
    
    // Print all three fields
    printStudent(&st);
}//end of main






