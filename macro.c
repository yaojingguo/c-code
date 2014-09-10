#include <stdio.h>

#define P(name) printf("%s\n", name);
#define Q(name) printf("name: %s, %s\n", name, (name));

int test0()
{
  P("ABC");
  Q("DEF");
}

#define abc def
#define def func

void func() 
{
  printf("hi, man\n");
}

int test1()
{
  abc();
}

int main()
{
  test0();
  test1();
}
