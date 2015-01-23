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

/*
The unicode for 中 is 0x4E2D.


UTF-8 encoding rules (For detaisl, refer to http://research.swtch.com/utf8)
     Unicode code points		UTF-8 encoding (binary)
          00-7F (7 bits)		0tuvwxyz
     0080-07FF (11 bits)		110pqrst 10uvwxyz
     0800-FFFF (16 bits)		1110jklm 10npqrst 10uvwxyz
 010000-10FFFF (21 bits)		11110efg 10hijklm 10npqrst 10uvwxyz

 0x4E2D is 11 bits. It is binary format is:

      binary:      0100  111000  101101
  UTF-8 bits:  1110    10      10
       UTF-8:  111001001011100010101101  0xe4b8ad

*/
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

