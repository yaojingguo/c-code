#include <stdio.h>
// See discussion about fewer initializers at:
// http://stackoverflow.com/questions/1352370/c-static-array-initialization-how-verbose-do-i-need-to-be

void info(int arr[], int len, char* name)
{
  int i;
  printf("======= name\n", name);
  for (i = 0; i < len; i++)
    printf("array[%d] = %d\n", i, arr[i]);
}

void test()
{
  int i;

  int first[5];
  info(first, 5, "first");

  int second[5] = {};
  info(second, 5, "second");

  int third[5] = {0};
  info(third, 5, "third");

  int fourth[5] = { 1 };
  info(fourth, 5, "fourth");

  int fifth[5] = { [0] = 10, [2] = 100, };
  info(fifth, 5, "fifth");
}

int main(int argc, const char *argv[]) 
{
  test();
  return 0;
}
