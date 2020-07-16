#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

// Allocate a node to be placed on the stack
// Returns the new node.
static Node* createNode(int num) {
	Node* nd = malloc(sizeof(Node));
	nd->number = num;    // Put the value in the node
	nd->next = NULL;     // Next pointer is null for now
	return nd;
}

// Initialize a new stack ADT. Returns the new stack instance.
// The caller is responsible for eventually freeing the returned pointer.
Stack* initStack(void) {
    Stack* sp = (Stack*)malloc(sizeof(Stack));
    sp->top = NULL;
    return sp;
}

// Check if the stack 'S' is empty.
// Pass a stack obtained from initStack().
// 'S' must not be NULL.
bool isEmpty(Stack* S) {
    return (S->top == NULL);
}

// Push the value 'num' on stack 'S'.
// Pass a stack obtained from initStack() as the first parameter.
void push(Stack* S, int num) {
	Node* newNode = createNode(num);
	newNode->next = S->top;
	S->top = newNode;
} 

// Pop the top item off the stack 'S'.
// Pass a stack obtained from initStack().
// Returns the value popped (number).
int pop(Stack* S) {
    if (isEmpty(S)) {
        return ROGUEVALUE; // Special value indicates error
    }
	else {
        int result = S->top->number;  // Get item
        Node* tmp = S->top;           // Temporarily store "top" (explain why this is needed)
        S->top = S->top->next;        // Unlink the top node
        free(tmp);                    // Free the popped node
        return result;     // Return the value
    }
} 

