#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Demostrate that errno is set only if the funciton call fails.

int main()
{
  struct stat buf;

  printf("errno: %d\n", errno);
  unlink("XXX");
  printf("errno: %d\n", errno);

  if (stat(__FILE__, &buf) != 0)
    printf("stat failed, errno: %d\n",  errno);
  else 
    printf("stat succeeded, errno: %d\n", errno);
  
  return 0;
}
