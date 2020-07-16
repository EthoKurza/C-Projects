#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

// Allocate a node to be placed in the queue.
// Returns the new node.
static Node* createNode(int num) {
	Node* nd = (Node*)malloc(sizeof(Node));
	nd->number = num;    // Put the value in the node
	nd->next = NULL;     // The next pointer is null for now
	return nd;
}

// Initialize a new queue ADT. Returns the new queue instance.
// The caller is responsible for eventually freeing the returned pointer.
Queue* initQueue(void) {
    Queue* qp = (Queue*)malloc(sizeof(Queue));
    qp->head = NULL;
    qp->tail = NULL;
    return qp;
}

// Check if the queue 'Q' is empty.
// Pass a queue pointer obtained from initQueue().
bool isEmpty(Queue* Q) {
    return (Q->head == NULL && Q->tail == NULL);
}

// Place the value 'num' on the tail of queue 'Q'.
// Pass a queue pointer obtained from initQueue() as the first parameter.
void enqueue(Queue* Q, int num) {
	Node* newNode = createNode(num);
	if (isEmpty(Q)) {
		Q->head = newNode;    // One item in the queue, both head and tail point at it
		Q->tail = newNode;
	}
	else {
		Q->tail->next = newNode;   // Add item at the tail
		Q->tail = newNode;
	}
} 

// Remove item at the head of the queue 'Q'.
// Pass a queue pointer obtained from initQueue().
// Returns the value dequeued (number).
int dequeue(Queue* Q) {
    if (isEmpty(Q)) {
        return ROGUEVALUE; // Special value indicates error
    }
	else {
        int result = Q->head->number;  // Get item from the head
        Node* tmp = Q->head;           // Temporarily store "head" (explain why this is needed)
        Q->head = Q->head->next;       // Unlink the head node
        if (Q->head == NULL) {         // If the queue became empty then show there is no tail
            Q->tail = NULL;
        }
            
        free(tmp);                     // Free the removed node
        return result;     // Return the value
    }
} 

