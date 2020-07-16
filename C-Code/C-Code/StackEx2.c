#include <stdio.h>
#include <stdbool.h>

#define MAXSTACK 200
#define ROGUEVALUE -2147483648

typedef struct {
    int top;          // Top of stack
    int ST[MAXSTACK]; // Array containing stack data
} Stack;

static Stack S;  // Variable S has source-file scope 

// Initialize the stack
void initStack(void) {
    S.top = -1;
}

// Check if the stack is empty
bool isEmpty(void) {
    return (S.top == -1);
}

// Push one number onto the stack.
void push(int num) {
    if (S.top == MAXSTACK - 1) {
        printf("Stack Overflow\n");  // Stack is full
    } else {
        ++S.top;            // Update top index
        S.ST[S.top] = num;  // Put 'num' on the stack
    }
} 

// Pop one number off the stack and return it.
int pop(void) {
    if (isEmpty()) {
        return ROGUEVALUE; // Special value indicates error
    } else {
        int result = S.ST[S.top];  // Get item
        --S.top;           // Update top index
        return result;     // Return item
    }
} 



int main(int argc, char** argv) {
    initStack();
    
    // Push numbers from 2 to 200
    for(int i=2; i <= 200;i++){
    	push(i);
	}
    
    // Pop and print all the numbers on the stack. Can also use: while (!isEmpty())
    while(!isEmpty()){
    	int num = pop();
    	if (num == ROGUEVALUE) {
            break;
        }
        printf("%d\n", num);
	}
    while (true) {
        int num = pop();
        if (num == ROGUEVALUE) {
        	printf("%d\n", num);
            break;
        }
        printf("%d\n", num);
    }
    
}
