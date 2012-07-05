#include <stdio.h>
#include <strings.h>
#include <string.h>

static void same(void *(*fn)(void *dest, const void *src, size_t n)) 
{
  char src[] = "ab";
  char dest[2];
  fn(dest, src, sizeof(src));
  printf("dest: %s\n", dest);
}

static void diff(void *(*fn)(void *dest, const void *src, size_t n)) 
{
  char arr[3];

  char * src = arr + 1;
  char * dest = arr;
  *src = 'a';
  *(src+1) = 'b';

  fn(dest, src, 2);
  printf("dest: %c%c\n", *dest, *(dest+1));  
}

static void test_bzero() 
{
  int i = 100;
  bzero(&i, sizeof i);
  printf("val: %d\n", i);
}

static void test_mem_funcs()
{
  same(memcpy);
  same(memmove);
  diff(memcpy);
  diff(memmove);
}

static void test_memset()
{
  char array[10];
  memset(array, 'x', 9);
  *(array+sizeof(array) - 1) = '\0';
  printf("array: %s\n", array);
}

int main(int argc, const char *argv[]) 
{
  test_bzero(); 
  test_mem_funcs();
  test_memset();
  return 0;
}
