/**
Name: Heyzzen Flores
Date: February 10, 2020
Project: Quiz 3: Data Logger
*/
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10

//declare datatype LogEntry
typedef struct{
	long int time;
	double temp;
}LogEntry;

//declare functions
void recordLog(void);
void printLog(void);

//declare logEntry Array
static LogEntry logArr[SIZE];

//main function
int main(int argc, char** argv){

	//call functions
	recordLog();
	printLog();
	
}//end of main

/*		functions		*/

//recordLog
void recordLog(void){
	
	for(int i =0; i < SIZE; i++){
		
		long int tm = time(NULL);			//get time
		
		//get temperatures from user and save both temperature and time into the array
		printf("Enter temperature reading %d: ", i+1);
		scanf("%lf", &logArr[i].temp);
		logArr[i].time = tm;
	}	
}//end of recordLog

//print log
void printLog(void){
	
	printf("\nTime (sec)	    Temperature (C)\n");
	//print each time and temp from the array
	for(int i =0; i < SIZE; i++){
		printf("%ld		%.1f\n",logArr[i].time, logArr[i].temp);
	}
}//end of printLog


