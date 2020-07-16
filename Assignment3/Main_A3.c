#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STRLEN 256

typedef struct node {
	char str[STRLEN];
	struct node* next;
	struct node* prev;
} Node;

//Nodes
static Node* head;
static Node* tail;

// Methods / Function declarations
Node* createNode(char str[]);
Node* lookup(Node* nd, char str[]);
int listSize(void);
bool add(char str[]);
void addNode(char str[]);
bool delete(Node* nd);
void deleteNode(char word[]);
void forwardPrint(void);
void reversePrint(void);


// Main
int main(int argc, char** argv) {
	
	// initialize linked list
	head = NULL;
	tail = NULL;
		
	// add strings: one, two, three, four, five
	addNode("one");
	addNode("two");
	addNode("three");
	addNode("four");
	addNode("five");
	
	//delete two and nine
	deleteNode("two");
	deleteNode("nine");
	
	//print size of the list
	printf("\nSize of the list: %d\n", listSize());
	
	// add strings: one, two, three, four, five
	addNode("two");
	addNode("three");
	addNode("five");
	addNode("six");
	addNode("seven");
	
	//print list
	puts("===== Forward print =====");		
	forwardPrint();
	puts("===== Reverse print =====");
	reversePrint();

}//end of main


//Methods
Node* createNode(char str[]) {
	Node* nd   = (Node*)malloc(sizeof(Node));
	strcpy(nd->str, str);
	nd -> next = NULL;
	nd -> prev = NULL;
	return nd;
}

Node* lookup(Node* nd, char str[]) {
	Node* result = NULL;
	Node* temp = nd;
	while(temp != NULL) {
		if(strcmp(temp->str,str) == 0) {
			result = temp;
			break;
		}
		temp = temp->next;
	}
	return result;
}

int listSize(void) {
	int count=1;

	//traverse at the starting node
	Node* temp = head;
	while(temp->next != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}


bool add(char str[]) {
	// Check if the string exists
	Node* nd = lookup(head,str);
	if(nd != NULL) {
		return true;
	}

	nd = createNode(str); 	// Allocate new node 'nd'
	if (head == NULL) { 	// If list is empty
		head = nd; 			// New node is the head (and tail)
	} else {
		tail->next = nd; 	// Make old tail node point at new one
		nd->prev = tail; 	// Make new node point back at old tail
	}
	tail = nd; 				// New node becomes the new tail
	return false;
}

void addNode(char str[]){
	if(add(str))
		printf("[ %s ] is a Duplicate Entry\n", str);
}

bool delete(Node* nd) {
	bool result = true;
	if (nd == head) { 				// Deleting head node?
		head = nd->next;
		result = false;
	}
	if (nd == tail) { 				// Deleting tail node?
		tail = nd->prev;
		result = false;
	}
	if (nd->next != NULL) { 		// Is there a next node?
		nd->next->prev = nd->prev;
		result = false;
	}
	if (nd->prev != NULL) { 		// Is there a previous node?
		nd->prev->next = nd->next;
		result = false;
	}
	free(nd); // Deallocate the deleted node
	return result;
}

void deleteNode(char word[]){
	Node* temp = lookup(head, word);		// Check if string exists
	if((temp == NULL) || (delete(temp))){	
		printf("[ %s ] was Not found", word);
	}
}


void forwardPrint(void) {
	// Loop as long as there are more nodes
	Node* temp = head;
	while (temp != NULL) {
		printf("%s\n", temp->str);
		temp = temp->next; // Go to the next node
	}
}

void reversePrint(void) {
// Loop as long as there are more nodes
	Node* temp = tail;
	while (temp != NULL) {
		printf("%s\n", temp->str);
		temp = temp->prev; // Go to the previous node
	}
}

