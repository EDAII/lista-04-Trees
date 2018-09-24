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

int max(int a, int b){
    if (a > b) {
        return a;
    }
    return b;
}


void rotateRight(Node *p){
  Node *q, *temp;

  q = p->left;
  temp = q->right;
  q->right = p;
  p->left = temp;
  p = q;
}


void rotateLeft(Node *p){
  Node *q, *temp;

  q = p->right;
  temp = q->left;
  q->left = p;
  p->right = temp;
  p = q;
}


void rotateLeftRight(Node *p){
  rotateLeft(p->left);
  rotateRight(p);
}


void rotateRightLeft(Node *p){
  rotateRight(p->right);
  rotateLeft(p);
}


Node* newNode(int item) {
    Node* node = (Node*) malloc(sizeof(Node));
    node -> data = item;
    node -> left = NULL;
    node -> right = NULL;
    node -> height = 0;

    return node;
}


void inorder(Node* root) {
    if (root != NULL) {
        inorder(root -> left);
        printf("%d \n", root -> data);
        inorder(root->right);
    }
}


int findHeight(Node *node) {
    if(node == NULL){
        return 0;
    }
    return node->height;
}


int findBalance(Node *node){
  if (node == NULL) {
    return 0;
  }
  return findHeight(node->left) - findHeight(node->right);
}


void insertAVL(Node* root, int data) {
    int balance;
    Node *last, *next, *new;

    if (root == NULL)
        root = newNode(data);

    else {
        if (root->data != data) {
            next = root;
            last = NULL;

            while (next != NULL) {
                last = next;
                if ( data <= next->data) {
				    next = next->left;
			    } else if (data > next->data) {
				    next = next->right;
			    }  
            }

            new = newNode(data);

            if(data < last->data){
                last->left = new;
            }
            else if(data > last->data){
                last->right = new;
            }

            root->height = 1 + max(findHeight(root->left), findHeight(root->right));
            balance = findBalance(root);

            
            if(balance > 1 && (root->left->data > data)){
                rotateRight(root);
            } else if (balance < -1 && (root->right->data < data)){
                rotateLeft(root);
            } else if (balance > 1 && (root->left->data < data)){
                rotateLeftRight(root);
            } else if (balance < -1 && (root->right->data > data)){
                rotateRightLeft(root);
            }
    
        }
    }
}


int searchInAST(int* vector, int size, int data) {
    Node* root = NULL;
   
    for (int index = 0; index < size; ++index)
        if
         (index == 0)
          insertAVL(root, vector[index]);
        else
          insertAVL(root, vector[index]);

    Node* result = search(root, data);

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


void printInOrderTree(Node *root){
  if(root != NULL){
    printInOrderTree(root->left);
    printf("%d \n", root->data);
    printInOrderTree(root->right);
  }
}


Node *destroyTree(Node *root){
  if(root->right != NULL){
    destroyTree(root->right);
  }
  if(root->left != NULL){
    destroyTree(root->left);
  }
  free(root);
  return NULL;
}