#include <stdio.h>

#define P(name) printf("%s\n", name);
#define Q(name) printf("name: %s, %s\n", name, (name));

#define eprintf(...) fprintf(stderr, __VA_ARGS__);

#define cat(name) fun##name

void test0()
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

void test1()
{
  abc();
}

void test2()
{
  eprintf("%d %s\n",  3, "pigs");
  cat(c)();
}

int main()
{
  test0();
  test1();
  test2();
}
