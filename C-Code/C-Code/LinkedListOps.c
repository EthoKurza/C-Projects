#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 256

typedef struct node {
	char str[STRLEN];        // The data in this node
	struct node* next;  // Pointer to the next node
} Node;

//static can only be used in the current C file that its declared in
static Node* head = NULL;		//declaring this as static makes it modular

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


int main(int argc, char** argv) {

	//last node
	Node* prev = NULL;

	int size =5;
	//printf("Enter %d strings: ",size);


	//for(int i = 0; i < size; i++) {
	char ch[STRLEN] = "";
	while(strcmp(ch, "999") != 0) {

		printf("Enter a string:");
		scanf("%s",ch);
		if(strcmp(ch,"999") != 0) {
			Node* nd = createNode(ch);
			if(head == NULL) {
				//It's the first node
				head = nd;
			} else {
				//any other node
				nd->next = prev->next;	// Link in the new node
				prev->next = nd;
			}
			prev = nd;
		}
		else{
			break;
		}

	}

	puts("");
	printList();

	printf("Size: %d", listSize());
	Node* nd = lookup(head, "two");
	if(nd != NULL)
		printf("found");
	else
		printf("not found");
	
	printf("Enter a String:");
	scanf("%s", ch);	
	add(ch);
	printList();

}
