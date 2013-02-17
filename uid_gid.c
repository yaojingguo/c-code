#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// There are 3 three user IDs for every process:
// 1) real user ID
// 2) effective user ID
// 3) saved set-user-ID
// fork will not change any of them. exec will not not change any of them if 
// set-user-ID bit is off.

void test_get_uid()
{
  uid_t real;
  uid_t effective;

  real = getuid();
  effective = geteuid();
  printf("real user ID: %d\n", real);
  printf("effective user ID: %d\n", effective);
}

void test_get_gid() 
{
  gid_t real;
  gid_t effective;

  real = getgid();
  effective = getegid();
  printf("real group ID: %d\n", real);
  printf("effective group ID: %d\n", effective);
}

int main(int argc, const char *argv[]) 
{
  test_get_uid();
  test_get_gid();
}
