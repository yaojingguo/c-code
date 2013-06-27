#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) 
{
  if (1, 0) 
    printf("wrong\n");
  if (0, 1)
    printf("right\n");
  return 0;
}
