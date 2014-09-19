#include <stdio.h>
#include "list.h"

struct fox {
  unsigned weight;
  struct list_head list;
};

void test1() 
{
  struct fox red_fox = {
    .weight      = 6,
    .list = LIST_HEAD_INIT(red_fox.list),
  };
  printf("weight: %u\n", red_fox.weight);
}

void test2()
{
  static LIST_HEAD(fox_list);
  struct fox f1 = { .weight = 1 };
  list_add(&f1.list, &fox_list);
  struct fox f2 = { .weight = 2 };
  list_add_tail(&f2.list, &fox_list);
  struct fox f0 = { .weight = 0 };
  list_add(&f0.list, &fox_list);

  struct list_head* p;
  struct fox *f;
  printf("Traversing...\n");
  list_for_each(p, &fox_list) {
    f = list_entry(p, struct fox, list);
    printf("weight: %u\n", f->weight);
  }

  printf("Traversing reversely...\n");
  list_for_each_entry_reverse(f, &fox_list, list) {
    printf("weight: %u\n", f->weight);
  }
}

int main(int argc, const char *argv[]) 
{
  test1();
  test2();
  return 0;
}
