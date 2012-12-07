#include <stdio.h>

int main(int argc, const char *argv[]) 
{
  char signed_input = '\x88';
  unsigned char unsigned_input = '\x88';
  char signed_output = signed_input >> 1;
  unsigned char unsigned_output = unsigned_input >> 1;
  printf("%x\n", signed_output);
  printf("%x\n", unsigned_output);
  return 0;
}
