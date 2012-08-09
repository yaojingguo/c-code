// TAB from http://cslibrary.stanford.edu/102/PointersAndMemory.pdf
#include <stdio.h>

int* TAB()
{
  int temp;
  return &temp;
}

void another() 
{
  int i[10] = {0};
}

// Call stack when calling TAB:
//  ----------
//  |call1
//  |TAB
//  ----------
// Call stack after calling TAB:
//  ----------
//  | call1
//  ----------
// ptr points to TAB's stack frame. Since no other function calls overwrite 
// TAB's stack frame, printf prints 42.
void call1()
{
  int* ptr;
  ptr = TAB();
  *ptr = 42;
  printf("val: %d\n", *ptr);
}

// Call stack when calling TAB:
//  ----------
//  |call1
//  |TAB
//  ----------
// Call stack after calling TAB:
//  ----------
//  | call1
//  ----------
// Call stack when calling another:
//  ----------
//  | call1
//  ----------
//  | another
//  ----------
// ptr points to TAB's stack frame. Since a call to another overwrites TAB's 
// stack frame with 0, printf prints 0.
void call2()
{
  int* ptr;
  ptr = TAB();
  *ptr = 42;
  another();
  printf("val: %d\n", *ptr);
}

int main(int argc, const char *argv[]) 
{
  call1();
  call2();
  return 0;
}
