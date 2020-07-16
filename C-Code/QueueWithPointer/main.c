#include <stdio.h>
#include "Queue.h"

int main(int argc, char** argv){
	//doesnt neeed the circular behaviour because its dynamically growing and freeing memory
	
	//initialize Queue
	Queue* Q = initQueue();		//stored as a local variable
	
	//add ints to queue
	enqueue(Q, 36);
	enqueue(Q, 15);
	enqueue(Q, 52);
	enqueue(Q, 23);
	
	//remove all items from the queue
	while(!isEmpty(Q)){
		printf("%d\n",dequeue(Q));
	}
	
	
}
