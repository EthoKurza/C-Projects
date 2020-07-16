#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"

#define MAXSTACK 200




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




