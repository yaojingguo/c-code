#include <stdio.h>

#define NO 0

int main(int argc, const char *argv[]) 
{
#if NO
  printf("#if\n");
#endif

#if defined(NO)
  printf("#if defined\n");
#endif

#ifdef NO
  printf("#ifdef\n");
#endif

  return 0;
}
