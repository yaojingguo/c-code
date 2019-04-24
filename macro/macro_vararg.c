#include <stdio.h>

// C99 way
#define debug1(format, ...)      fprintf(stderr, format, __VA_ARGS__)

// GNU CPP
#define debug2(format, ...)      fprintf(stderr, format, ## __VA_ARGS__)
#define debug3(format, args...)  fprintf (stderr, format, ##args)

int main(int argc, const char *argv[]) 
{
  debug1("I am %s!\n", "jingguo");
  // Can't compile
  // debug1("I am a hacker!\n");
  printf("\n");

  debug2("I am %s!\n", "jingguo");
  debug2("I am a hacker!\n");
  printf("\n");

  debug3("I am %s!\n", "jingguo");
  debug3("I am a hacker!\n");

  return 0;
}
