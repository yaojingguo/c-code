#include <stdio.h>
// See discussion about fewer initializers at:
// http://stackoverflow.com/questions/1352370/c-static-array-initialization-how-verbose-do-i-need-to-be
void func()
{
  int array[10] = {};
  int i;

  for (i = 0; i < 10; i++)
    printf("array[%d] = %d\n", i, array[i]);
}

int main(int argc, const char *argv[]) 
{
  func();
  return 0;
}



