#include <stdio.h>

struct list_head {
  struct list_head *prev;
  struct list_head *next;
};

int main(int argc, const char *argv[]) 
{
  struct list_head head = {&head, &head};
  return 0;
}
