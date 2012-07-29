#include <stdio.h>
#include <stdlib.h>

// Given a binary tree, return its leftmost path -- the nodes along the 
// leftmost path from the root node down to the farthest leaf node. Error 
// handling and resource freeing are omitted.

struct lnode {
  int data;
  struct lnode* next;
};

struct list {
  int size;
  struct lnode* head;
};

struct tnode {
  int data;
  struct tnode* left;
  struct tnode* right;
};

struct list* new_list()
{
  struct list* ls = (struct list*) malloc(sizeof(struct list));
  ls->size = 0;
  ls->head = NULL;
  return ls;
}

struct lnode* new_linknode(int data)
{
  struct lnode* node = (struct lnode*) malloc(sizeof(struct lnode));
  node->data = data;
  node->next = NULL;
}

struct tnode* new_treenode(int data) 
{ 
  struct tnode* node = (struct tnode*) malloc(sizeof(struct tnode));    
  node->data = data; 
  node->left = NULL; 
  node->right = NULL;
  return node; 
} 

void info_list(struct list* ls)
{
  struct lnode* p = ls->head;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
}

struct list* leftmostPath(struct tnode* node)
{
  if (node == NULL) return new_list();
  struct list* lp = leftmostPath(node->left);
  struct list* rp = leftmostPath(node->right);
  struct list* sub = lp->size >= rp->size ? lp : rp;

  sub->size++;
  struct lnode* current = new_linknode(node->data);
  current->next = sub->head;
  sub->head = current;
  return sub;
}

int main(int argc, const char *argv[]) 
{
  // Build a tree:
  //       4
  //     /   \
  //    2     5
  //  /   \
  // 1     3
  //        \
  //         7 
  struct tnode* _2 = new_treenode(2);
  _2->left = new_treenode(1);
  struct tnode* _3 = new_treenode(3);
  _3->right = new_treenode(7);
  _2->right = _3;

  struct tnode* _4 = new_treenode(4);
  _4->left = _2;
  _4->right = new_treenode(5);

  struct list* path = leftmostPath(_4);
  info_list(path);
  
  return 0;
}
