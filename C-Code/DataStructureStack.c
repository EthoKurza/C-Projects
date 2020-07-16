#include <stdio.h>
#include <stdbool.h>

#define MAXSTACK 20
#define ROGUEVALUE -214783648		//most negative an int can have


typedef struct {
	int top;          // Top of stack
	int ST[MAXSTACK]; // Array containing stack data
} Stack;

//declare variables
static Stack S;

//declare functions
void initStack(void);
bool isEmpty(void);
void push(int num);
int pop(void);

int main(int argc, char** argv) {
	//create a stack
	initStack();

	//push/add some numbers
	push(36);
	push(15);
	push(52);
	push(23);
	
	//pop and print all numbers on the stack
	while(!isEmpty())
		printf("Popped: %d\n", pop());
	
	//another way to print the stack
	while(true){
		int num = pop();
		if(num == ROGUEVALUE){		//checks if the next value is a ROGUEVALUE
			break;
		}
		printf("Popped: %d\n", pop());
	}
		
		


}//end of main

void initStack(void) {
	S.top = -1;

	
}

bool isEmpty(void) {
	return (S.top == -1);
}

void push(int num) {
	if  (S.top == MAXSTACK -1) {
		printf("Stack Overflow\n");  // Stack is full
	} 
	else {
		++S.top;            // Update top index
		S.ST[S.top] = num;  // Put 'num' on the stack
	}
}

int pop(void) {
	if (isEmpty()) {
		return ROGUEVALUE; // Special value indicates error
	} 
	else {
		int result = S.ST[S.top];  // Get item
		--S.top;           // Update top index
		return result;     // Return item
	}
}
