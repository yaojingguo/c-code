#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Demo that it is possible to write after unlink.
// Run "touch file" before running this program.

int main(int argc, const char *argv[]) 
{
  int fd;
  char* name = "file";

  if ((fd = open(name, O_WRONLY)) < 0) {
    goto bad;
  }
  if (unlink(name) != 0) {
    goto bad;
  }
  if (write(fd, "AB", 2) != 2) {
    goto bad;
  }
  if (close(fd) != 0) {
    goto bad;
  }
  return 0;
bad:
    perror(NULL);
    exit(1);
}
