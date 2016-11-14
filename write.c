#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int fd = 2;
  /* close(fd); */
  write(fd, "abc", 4); 
  return 0;
}
