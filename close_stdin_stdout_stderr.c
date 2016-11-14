#include <unistd.h>
#include <stdio.h>

void close_stdin() {
  char buf[10] = { 0 };
  int count;

  /* close(0); */

  count = read(0, buf, 9);

  printf("count: %d\n", count);
  printf("buf: %s\n", buf);
}

void close_stdout() {
  int fd = 1;
  /* close(fd); */
  write(fd, "abc", 4); 
  return 0;
}

void close_stderr() {
  int fd = 2;
  /* close(fd); */
  write(fd, "abc", 4); 
  return 0;
}

int main(int argc, char *argv[])
{
  return 0;
}

