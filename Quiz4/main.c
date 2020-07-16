#include <stdio.h>
#include "Queue.h"

//function declarations
void transmit(char data[]);
void recieve(int length);

//delcare Queue
static Queue* Q;

int main(int argc, char** argv){
	
	//initialize queue
	Q = initQueue();
	
	
	transmit("The quick brown fox jumps over the lazy dog");
	transmit("Don\'t cut corners");
	transmit("Spot barked up the wrong tree");
	
	recieve(30);
	recieve(40);
	recieve(25);
	
}

void transmit(char data[]){
	
	char* tempChar = data;
	
	while(*tempChar != '\0'){
		enqueue(Q, *tempChar);
		tempChar++;
	}
	
}

void recieve(int length){
	int count = 0;
	
	while(!isEmpty(Q)){

		if(count < length){
			printf("%c",dequeue(Q));
		}
		else{
			printf("\n");		//new line
			break;		//get out of the loop
		}
		count++;
	}
	
}
