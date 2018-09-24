#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "tree.h"

/* Measuring performance
    clock_t begin = clock();
       # here, do your time-consuming job
    clock_t end = clock();

->    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
*/

Node* newNode(int item) {
    Node* node = (Node*) malloc(sizeof(Node));
    node -> data = item;
    node -> left = NULL;
    node -> right = NULL;

    return node;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root -> left);
        printf("%d \n", root -> data);
        inorder(root->right);
    }
}


Node* insert(Node* node, int data) {
    if (node == NULL)
        return newNode(data);

    if (data < node -> data)
        node->left = insert(node->left, data);
    else if (data > node -> data)
        node->right = insert(node->right, data);

    return node;
}

int searchInAST(int* vector, int size, int value) {
    Node* root = NULL;
   
    for (int index = 0; index < size; ++index)
        if (index == 0)
          root  = insert(root, vector[index]);
        else
          insert(root, vector[index]);

    Node* result = search(root, value);

    if(result != NULL) 
        return 1;
    else 
        return -1;
}

Node* search(Node* root, int data) {
    if (root == NULL || root -> data == data)
       return root;
    
    if (root -> data < data)
       return search(root -> right, data);

    return search(root->left, data);
}

