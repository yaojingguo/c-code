#include <stdio.h>
#include <string.h>

void test1() 
{
  char c1, c2;
  scanf("%c", &c1);
  scanf("%c", &c2);
  printf("c1: |%c|, c2: |%c|", c1, c2);
}

void test2()
{
  char c1, c2;
  scanf("%c %c", &c1, &c2);
  printf("c1: |%c|, c2: |%c|", c1, c2);
}

void test3() 
{
  char c1, c2;
  scanf("%c", &c1);
  scanf(" %c", &c2);
  printf("c1: |%c|, c2: |%c|", c1, c2);
}

void test4()
{
  printf("%s\n", "中国");
  printf("%ld\n", strlen("中国"));
}

void test5()
{
  char *c = "中";
  int i;

  printf("Zhong: %s\n", c);
  for (i = 0; i < 4; i++)
    printf("%d: %x\n", i, 0xff & c[i]);

  char arr[4];
  memset(arr, 0, 4);
  scanf("%3c", arr);
  for (i = 0; i < 4; i++)
    printf("%d: %x\n", i, 0xff & arr[i]);
  printf("Echo: %s\n", arr);
}

int main()
{
  // test1();
  // test2();
  // test3();
  // test4();
  test5();
}

