#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define LEN 1024


void test_gethostname()
{
  char name[LEN];
  if (gethostname(name, LEN) != 0) {
    perror(NULL);
    exit(EXIT_FAILURE);
  }
  printf("host name: %s\n", name);
}


int main(int argc, char *argv[])
{
  test_gethostname();
  return 0;
}
