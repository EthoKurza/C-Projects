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

// Print the fields of a student structure
void printStudent(Student st) {
    printf("Student's name: %s %c %s\n", st.name.first, st.name.middle, st.name.last);
    printf("Student ID: %d\n", st.id);
    printf("Student's GPA: %f\n", st.GPA);    
}

int main(int argc, char** argv) {
    Student st;
    
    // input all three fields of 'st'
    printf("Please enter the student's name, ID, and GPA: ");
    scanf("%s%d%lf", st.name, &st.id, &st.GPA);
    
    // Print all three fields
    printStudent(st);
}
