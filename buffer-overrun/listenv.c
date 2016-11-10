#include <unistd.h>
#include <stdio.h>

extern char **environ;
int main() {
  int i = 0;
  while(environ[i]) {
    char *p = environ[i++];
    printf("%p: %s\n", p, p);
  }
}
