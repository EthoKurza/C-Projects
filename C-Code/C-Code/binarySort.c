#include <stdio.h>
#include <string.h>

#define MAX_WORD_SIZE 256

//typedef struct {
//	char word[MAX_WORD_SIZE];
//} NodeData;

typedef struct {
	char word[MAX_WORD_SIZE];
} TreeNode;

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
	printf("%s ", node->data.word);
}

void preOrder(TreeNode* node) {
	if (node != NULL) {
		visit(node); // Process node, e.g print
		preOrder(node->left);
		preOrder(node->right);
	}
}


