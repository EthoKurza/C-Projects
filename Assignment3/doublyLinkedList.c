#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doublyLinkedList.h"


Node* createNode(char str[]) {
	Node* nd   = (Node*)malloc(sizeof(Node));		//allocates a space for 1 node
	strcpy(nd->str, str);
	//nd -> str = str; // Put the value in the noden
	nd -> next = NULL;  // Next pointer is null for now
	return nd;    // Return a pointer to the new node
}

void printList(void) {
	Node* temp = head;  // Start at head
	//  Loop as long as there are more nodes
	while (temp != NULL) {
		printf("%s\n", temp->str);
		temp = temp->next; // Go on to the next node
	}
}

Node* lookup(Node* nd, char str[]) {
	Node* result = NULL;
	Node* temp = nd;		// traverse starting at given node
	while(temp != NULL) {
		if(strcmp(temp->str,str) == 0) {		//found a match?
			result = temp;			//return the current node
			break;
		}
		temp = temp->next;			//go to next node
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

void add(char str[]){
	// Check if the string exists
	Node* nd = lookup(head,str);
	if(nd != NULL){
		return;
	}

	//traverse to the last item in the list
	Node* temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;	
		
	}
	nd = createNode(str);
	//nd->next = temp->next;		//not really needed
	temp->next = nd;
}


