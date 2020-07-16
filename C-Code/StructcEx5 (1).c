#include <stdio.h>
#include <stdbool.h>

#define NUM_ST 3

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
	printf("Student's name: %s\n", st.name);
	printf("Student ID: %d\n", st.id);
	printf("Student's GPA: %f\n", st.GPA);
}

int main(int argc, char** argv) {
	Student st[NUM_ST];

	// input all three fields of 'st'
	for (int i = 0; i < NUM_ST; i++) {
		printf("Please enter the student First Name, Middle Name, Last Name, ID, and GPA for student %d: ", i);
		scanf("%s %c %d %d %lf", st[i].name.first,st[i].name.middle,st[i].name.last, &st[i].id, &st[i].GPA);
	}

	// Print all fields of all students
	for (int i = 0; i < NUM_ST; i++) {
		printStudent(st[i]);
	}
}
