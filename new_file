#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
/*
 * Sample code from tee man page.
 * To compile it, run "gcc -o my-tee tee_splice.c".
 * To run it, run "cat tee_splice.c | ./my-tee new_file | grep int".
 */ 
int
main(int argc, char *argv[])
{
  int fd;
  int len, slen;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  do {
    /*
     * tee stdin to stdout.
     */
    len = tee(STDIN_FILENO, STDOUT_FILENO,
        INT_MAX, SPLICE_F_NONBLOCK);

    if (len < 0) {
      if (errno == EAGAIN)
        continue;
      perror("tee");
      exit(EXIT_FAILURE);
    } else
      if (len == 0)
        break;

    /*
     * Consume stdin by splicing it to a file.
     */
    while (len > 0) {
      slen = splice(STDIN_FILENO, NULL, fd, NULL,
          len, SPLICE_F_MOVE);
      if (slen < 0) {
        perror("splice");
        break;
      }
      len -= slen;
    }
  } while (1);

  close(fd);
  exit(EXIT_SUCCESS);
}
