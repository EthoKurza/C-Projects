#include <stdio.h>
#include "Tree.h"

int main(int argc, char** argv) {
	FILE* in = fopen("btree.txt", "r");
	if(in == NULL){
		printf("Error!\n");
		return 0;
	}
	BinaryTree bt;
	bt.root= buildTree(in);
	
	//Print the tree contents using pre-order traversal
	puts("Pre-Order:\n");
	preOrder(bt.root);
	
	puts("\n\nIn-Order:\n");
	inOrder(bt.root);
	
	puts("\n\nPost-Order:\n");
	postOrder(bt.root);
	
	// Print number of nodes
	puts("\n");	//new line
	printCount();
	
	
}
