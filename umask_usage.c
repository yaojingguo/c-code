#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// Code to show the effect of umask, the following link is a good reference:
// http://askubuntu.com/questions/44542/what-is-umask-and-how-does-it-work

void exit_failure()
{
  perror(NULL);
  exit(EXIT_FAILURE);
}

void create_file(const char *pathname, mode_t mode)
{
  int fd;

  if ((fd = creat(pathname, mode)) < 0)
    exit_failure();

  if (write(fd, "A\n", 2) < 0)
    exit_failure();

  if (close(fd) != 0)
    exit_failure();
}

int main(int argc, char *argv[])
{
  create_file("0666", 0666); 
  create_file("0777", 0777); 
  return 0;
}
