#include <linux/list.h>
#include <stdio.h>

struct fox {
  unsigned tail_length;
  unsigned weight;
  bool     is_fantastic;
  struct list_head list;
};

int main(int argc, const char *argv[]) 
{
  struct fox red_fox = {
    .tail_length = 40,
    .weight      = 6,
    .list = LIST_HEAD_INIT(red_fox.list),
  };
  printf("weight: %u\n", red_fox.weight);
  return 0;
}
