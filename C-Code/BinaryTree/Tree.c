#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Tree.h"


static int count = 0;

TreeNode* buildTree(FILE* in) {
	char str[MAX_WORD_SIZE];
	int cnt = fscanf(in, "%s", str);
	if (cnt != 1 || strcmp(str, "@") == 0)
		return NULL;
	TreeNode* p = (TreeNode*) malloc(sizeof(TreeNode));
	strcpy(p->data.word, str); // data not a ptr, use .
	p->left = buildTree(in);
	p->right = buildTree(in);
	return p;
}

void visit(TreeNode* node) {
	count++;
	printf("%s ", node->data.word);
}

void preOrder(TreeNode* node) {
	if (node != NULL) {
		visit(node); // Process node, e.g print
		preOrder(node->left);
		preOrder(node->right);
	}
}

void inOrder(TreeNode* node) {
	if (node != NULL) {
		inOrder(node->left);
		visit(node); // Process node, e.g print
		inOrder(node->right);
	}
}

void postOrder(TreeNode* node) {
	if (node != NULL) {
		postOrder(node->left);
		postOrder(node->right);
		visit(node); // Process node, e.g print
	}
}

int numNodes(TreeNode* root) {
	if (root == NULL)
		return 0;
	return 1 + numNodes(root->left)
	       + numNodes(root->right);
}

void printCount(void){
	printf("The number of nodes is %d\n", count);
}



