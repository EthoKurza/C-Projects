//header file 

#define MAX_WORD_SIZE 256


typedef struct {

	char word[MAX_WORD_SIZE];
} NodeData;

typedef struct treenode {
	NodeData data; // struct inside a struct
	struct treenode* left;
	struct treenode* right;
} TreeNode;

typedef struct {
	TreeNode* root;
} BinaryTree;

TreeNode* buildTree(FILE* in);
void visit(TreeNode* node);
void preOrder(TreeNode* node);
void inOrder(TreeNode* node);
void postOrder(TreeNode* node);
int numNodes(TreeNode* root);
void printCount(void);

