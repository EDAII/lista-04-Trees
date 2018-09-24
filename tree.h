typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* newNode(int item);
Node* insert(Node* node, int data);
Node* search(Node* root, int data);

void inorder(Node* root);
int searchInAST(int* vector, int size, int value);
