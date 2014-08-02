#include <stdio.h>

#define P(name) printf("%s\n", name);
#define Q(name) printf("name: %s, %s\n", name, (name));

int main()
{
  P("ABC");
  Q("DEF");
}
