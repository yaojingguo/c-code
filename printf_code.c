#include <stdio.h>

#define SIZE 10000

// One printf may invoke write system call multiple times.
int main(int argc, const char *argv[]) 
{
  char msg[SIZE];
  msg[SIZE-1] = '\0';
  for (int i = 0; i < SIZE - 1; i++)
    msg[i] = 'a';
  printf("msg: %s\n", msg);
  return 0;
}
