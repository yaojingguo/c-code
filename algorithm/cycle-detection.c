#include <stdio.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

struct node {
  int data;
  struct node* next;
};

// Use Floyd's cycle-finding algorithm.
int has_loop(struct node* head)
{
  struct node *turtle, *rabbit;

  if (head == NULL)
    return FALSE;
  turtle = head;
  rabbit = head->next;
  while (rabbit != NULL) 
    if (rabbit == turtle)
      return TRUE;
    else if (rabbit->next == NULL)
      return FALSE;
    else {
      turtle = turtle->next;
      rabbit = rabbit->next->next;
    }
  return FALSE;
}

void test()
{
  {
    struct node node1;
    node1.data = 1;
    node1.next = &node1;
    assert(has_loop(&node1));
  } 
  {
    struct node node1, node2;
    node1.data = 1;
    node1.next = &node2;
    node2.data = 2;
    node2.next = NULL;
    assert(!has_loop(&node1));
  }
  {
    struct node node1, node2;
    node1.data = 1;
    node1.next = &node2;
    node2.data = 2;
    node2.next = &node1;
    assert(has_loop(&node1));
  }
  {
    struct node node1, node2, node3, node4;
    node1.data = 1;
    node1.next = &node2;
    node2.data = 2;
    node2.next = &node3;
    node3.data = 3;
    node2.next = &node4;
    node4.data = 4;
    node4.next = &node2;
    assert(has_loop(&node1));
  }
}

int main(int argc, const char *argv[]) 
{
  test();
  return 0;
}
