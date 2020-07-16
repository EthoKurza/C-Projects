#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct node {
	int  number;        // The data in this node
	struct node* next;  // Pointer to the next node
} Node;

//static can only be used in the current C file that its declared in
static Node* head = NULL;		//declaring this as static makes it modular

Node* createNode(int num) {
	Node* nd   = (Node*)malloc(sizeof(Node));		//allocates a space for 1 node
	nd -> number = num; // Put the value in the noden
	nd -> next = NULL;  // Next pointer is null for now
	return nd;    // Return a pointer to the new node
}


void printList(void) {
	Node* temp = head;  // Start at head
	//  Loop as long as there are more nodes
	while (temp->next != NULL) {
		printf("%d\n", temp->number);
		temp = temp->next; // Go on to the next node
	}
}

Node* searchList(Node* nd, int num) {
	Node* result = NULL;
	Node* temp = nd;		// traverse starting at given node
	while(temp != NULL) {
		if(temp->number == num) {		//found a match?
			result = temp;			//return the current node
			break;
		}
		temp = temp->next;			//go to next node
	}
	return result;
}

void add(int num){

	//traverse to the last item in the list
	Node* temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;	
		
	}
	Node* nd = createNode(num);
	//nd->next = temp->next;		//not really needed
	temp->next = nd;
}

bool 

int main(int argc, char** argv) {

	//last node
	Node* prev = NULL;

	int size =5;
	printf("Enter %d number: ",size);
	for(int i = 0; i < size; i++) {
		int num;
		scanf("%d",&num);

		Node* nd = createNode(num);
		if(head == NULL) {
			//It's the first node
			head = nd;
		} else {
			//any other node
			Node* temp = head;
			//Node* tempPrev;
			//int count = 1;

			//find the location of where the number is less than
			while(temp != NULL) {
				puts("Checking!");
				if(temp->number < num) {
					puts("Less!");
					add(num);
					break;
				} else {
					puts("More!");
					nd->next = prev->next;	// Link in the new node
					prev->next = nd;
					break;
				}
				temp = temp->next;		//go to next node

			}

		}
		prev = nd;
		
	}
	
	puts("");
	printList();


}
