#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char *ptr = (char*) malloc(10); 
  printf("%p\n", ptr);
  return 0;
}
