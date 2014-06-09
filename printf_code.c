#include <stdio.h>

#define SIZE 10000

// One printf may invoke write system call multiple times.
// Refer to "man 3 stdio" and "man 3 flockfile".
// http://stackoverflow.com/questions/467938/stdout-thread-safe-in-c-on-linux
void test1()
{
  char msg[SIZE];
  msg[SIZE-1] = '\0';
  for (int i = 0; i < SIZE - 1; i++)
    msg[i] = 'a';
  printf("msg: %s\n", msg);
}

void test2()
{
	printf("%10s\n", "abc");
	printf("%.s\n", "abc");
	printf("%2d\n", 19999);
	printf("%.6d\n", 12345);
	printf("%a\n", 8.5);
	printf("%a\n", 1024.0);
	printf("%a\n", 512.0);
  float a = 0.1;
	printf("%.17f\n", a);
}

int main(int argc, const char *argv[]) 
{
  // test1();
  test2();
  return 0;
}
