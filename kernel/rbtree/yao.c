#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"

struct bitch {
  struct rb_node node;
  int no;
};

struct rb_root mytree = RB_ROOT;

struct bitch * search(struct rb_root *root, int no)
{
  struct rb_node *cur_node = root->rb_node;
  struct bitch *data;

  while (cur_node) {
    data = container_of(cur_node, struct bitch, node);
    if (no < data->no)
      cur_node = cur_node->rb_left;
    else if (no > data->no)
      cur_node = cur_node->rb_right;
    else
      return data;
  }
  return NULL;
}

int insert(struct rb_root *root, struct bitch *data)
{
  struct rb_node **new;
  struct rb_node *parent;
  struct bitch *this;

  new = &(root->rb_node);
  parent = NULL;

  while (*new) {
    this = container_of(*new, struct bitch, node);
    parent = *new;
    if (data->no < this->no)
      new = &((*new)->rb_left);
    else if (data->no > this->no)
      new = &((*new)->rb_right);
    else
      return 0;
  }
  rb_link_node(&data->node, parent, new);
  rb_insert_color(&data->node, root);
  return 1;
}

void my_free(struct bitch *data)
{
  if (data != NULL)
    free(data);
}

#define N 32

int main()
{
  int i;
  struct bitch *arr[N];
  
  printf("Insert\n");
  for (i = 0; i < N; i++) {
    arr[i] = (struct bitch *) malloc(sizeof(struct bitch));
    arr[i]->no = i;
    insert(&mytree, arr[i]);
  }

  struct rb_node* cur_node;
  printf("Traverse\n");
  for (cur_node = rb_first(&mytree); cur_node; cur_node = rb_next(cur_node)) 
    printf("no = %d\n", rb_entry(cur_node, struct bitch, node)->no);

  printf("Delete node 4\n");
  struct bitch *data = search(&mytree, 4);
  if (data) {
    rb_erase(&data->node, &mytree);
    my_free(data);
  }

  printf("Traverse again\n");
  for (cur_node  = rb_first(&mytree); cur_node; cur_node = rb_next(cur_node))
    printf("no  = %d\n", rb_entry(cur_node, struct bitch, node)->no);

  return 0;
}

