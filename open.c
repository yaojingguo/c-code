#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) 
{
  int fd;
  fd = open("new-file", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
  if (fd == -1) {
    perror(NULL);
    exit(1);
  }

  char *buf = "abc";
  size_t count = 1;
  int written;
  written = write(fd, buf, count);

  if (written != -1)
    printf("written: %d\n", written);

  if (write(fd, "xxx\n", 4) != 4)
    printf("writen error\n");

  close(fd);
  return 0;
}
