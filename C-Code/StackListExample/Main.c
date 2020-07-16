#include <stdio.h>
#include "Stack.h"

int main(int argc, char** argv){
	//initialize stack
	Stack* S = initStack();
	
	//push data into stack
	push(S, 36);
	push(S, 15);
	push(S, 52);
	push(S, 23);
	
	//pop all numbers and print them
	while(!isEmpty(S)){
		printf("%d\n",pop(S));
	}
	
}//end of main
