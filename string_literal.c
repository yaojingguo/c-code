#include <stdio.h>

int main(int argc, const char *argv[]) 
{
  char *literal = "ABC" "DEF";
  printf("literal: %s\n", literal);
  return 0;
}
