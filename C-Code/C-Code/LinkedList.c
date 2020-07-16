#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	int  number;        // The data in this node
	struct node* next;  // Pointer to the next node
} Node;

//static can only be used in the current C file that its declared in
static Node* head = NULL;		//declaring this as static makes it modular
static Node* tail = NULL;

Node* createNode(int num) {
	Node* nd   = (Node*)malloc(sizeof(Node));		//allocates a space for 1 node
	nd -> number = num; // Put the value in the noden
	nd -> next = NULL;  // Next pointer is null for now
	return nd;    // Return a pointer to the new node
}

void printList(void) {
	Node* temp = head;  // Start at head
	//  Loop as long as there are more nodes
	while (temp != NULL) {
		printf("%d\n", temp->number);
		temp = temp->next; // Go on to the next node
	}
}

int main(int argc, char** argv) {

	int size =5;
	printf("Enter %d number: ",size);
	for(int i = 0; i < size; i++) {
		int num;
		scanf("%d",&num);

		Node* nd = createNode(num);
		nd -> next = head;
		head = nd;
	}

	printList();


}
