#include <stdio.h>
#include <stdlib.h>



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
	while (temp != NULL) {
		printf("%d\n", temp->number);
		temp = temp->next; // Go on to the next node
	}
}

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
			nd->next = prev->next;	// Link in the new node
			prev->next = nd;
		}
		prev = nd;
	}

	puts("");
	printList();
	
	//delete the 4th item in the list
	Node* temp = head;
	//traverse to find the 4th item
	int count = 1;
	while(temp->next != NULL){
		
		if(count++ == 4){
			break;	
		}
		prev = temp;
		temp = temp->next;
		//count++;
	}
	
	// Did we stop loop early?
	if(temp == NULL){
		printf("List is too short");
		return 0;		//exits program
	}
	
	
	if (temp == head) {  // Is this the first node?
		head = temp->next;
	} else {
		prev->next = temp->next;
	}
	
	puts("");
	printList();
	free(temp);  // Deallocated the deleted node, if this isnt done, it will cause a memeory leak

}


