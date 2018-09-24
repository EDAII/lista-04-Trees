typedef struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} Node;

int max(int a, int b);
void rotateRight(Node *p);
void rotateLeft(Node *p);
void rotateLeftRight(Node *p);
void rotateRightLeft(Node *p);
int findHeight(Node *node);
int findBalance(Node *node);
Node* newNode(int item);
void insertAVL(Node* node, int data);
Node* search(Node* root, int data);

void inorder(Node* root);
int searchInAST(int* vector, int size, int value);
void printInOrderTree(Node *root);
Node *destroyTree(Node *root);