#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

#define RANGE 100
#define MAX 10


int main(void) {
  Node *root = (Node *) malloc (sizeof(Node));
  int i, t;
  srand((unsigned)time(NULL));
  for(i = 0; i < MAX; i++){
      t = rand() % RANGE;
    insertAVL(root, t);
  }
  printInOrderTree(root);
  destroyTree(root);
  return 0;
}
