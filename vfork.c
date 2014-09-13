#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main()
{
  pid_t child;

  child = vfork();

  printf("errno: %d\n", errno);
  printf("ENOSYS: %d\n", ENOSYS);

  if (child == 0) {
    printf("parent\n");
    exit(0);
  } else if (child > 0) {
    printf("child\n");
  } else {
    printf("vfork failed\n");
  }
}
