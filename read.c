#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  char buf[10] = { 0 };
  int count;

  /* close(0); */

  count = read(0, buf, 9);

  printf("count: %d\n", count);
  printf("buf: %s\n", buf);
   
  return 0;
}
