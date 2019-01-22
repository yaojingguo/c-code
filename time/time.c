#include <time.h>
#include <stdio.h>

int main() {
  time_t now = time(NULL);
  printf("now: %ld\n", now);
}
