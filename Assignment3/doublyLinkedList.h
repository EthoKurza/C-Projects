#define STRLEN 256

typedef struct node {
	char  str[256];        
	struct node* next;  
} Node;

//static can only be used in the current C file that its declared in
static Node* head = NULL;		//declaring this as static makes it modular
static Node* tail = NULL;


Node* createNode(char str[]);
void printList(void);
Node* lookup(Node* nd, char str[]);
int listSize(void);
void add(char str[]);
