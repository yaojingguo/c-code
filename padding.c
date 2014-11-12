#include <stdio.h>

struct animal_struct {
  char dog;           // 1 byte
  unsigned int cat;   // 4 bytes
  unsigned short pig; // 2 bytes
  char fox;           // 1 byte
};

struct animal_compact_struct {
  unsigned int cat;   // 4 bytes
  unsigned short pig; // 2 bytes
  char dog;           // 1 byte
  char fox;           // 1 byte
};

int main()
{
  printf("animal_struct's size: %ld\n", sizeof(struct animal_struct));
  printf("animal_compact_struct's size: %ld\n", sizeof(struct animal_compact_struct));

  return 0;
}
