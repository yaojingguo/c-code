#include <stdio.h>
#include <stdlib.h>

void p(const char *s)
{
  
  printf("%s? (y/n): ", s == NULL ? "Continue" : s);
  char c;
  scanf("%c", &c);
  getchar();
  if (c != 'y') {
    exit(0);
  }
}

void __exit_failure(const char *s) 
{
  perror(s);
  exit(EXIT_FAILURE);
}

void exit_failure() 
{
  __exit_failure(NULL);
}
