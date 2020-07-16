#include <stdio.h>
#include "Queue.h"

int main(int argc, char** argv){
	//doesnt neeed the circular behaviour because its dynamically growing and freeing memory
	
	//initialize Queue
	Queue* Q = initQueue();
	
	//add ints to queue
	enqueue(Q, 'H');
	enqueue(Q, 'e');
	enqueue(Q, 'y');
	enqueue(Q, 'z');
	enqueue(Q, 'z');
	enqueue(Q, 'e');
	enqueue(Q, 'n');
	
	while(!isEmpty(Q)){
		printf("%c\n",dequeue(Q));
	}
	
	
}
