#include <sys/types.h>
#include <sys/mman.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Does not work on OS X, as you can't mmap over /dev/zero */
int main(void)
{
  const char str1[] = "string 1";
  const char str2[] = "string 2";
  int parpid = getpid(), childpid;
  int fd = -1;
  char *anon, *zero;

  if ((fd = open("/dev/zero", O_RDWR, 0)) == -1)
    err(1, "open");

  anon = (char*)mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED, -1, 0);
  zero = (char*)mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_FILE|MAP_SHARED, fd, 0);

  if (anon == MAP_FAILED || zero == MAP_FAILED)
    errx(1, "either mmap");

  strcpy(anon, str1);
  strcpy(zero, str1);

  printf("PID %d:\tanonymous %s, zero-backed %s\n", parpid, anon, zero);
  switch ((childpid = fork())) {
    case -1:
      err(1, "fork");
      /* NOTREACHED */
    case 0:
      childpid = getpid();
      printf("PID %d:\tanonymous %s, zero-backed %s\n", childpid, anon, zero);
      sleep(3);

      printf("PID %d:\tanonymous %s, zero-backed %s\n", childpid, anon, zero);
      munmap(anon, 4096);
      munmap(zero, 4096);
      close(fd);
      return EXIT_SUCCESS;
  }

  sleep(2);
  strcpy(anon, str2);
  strcpy(zero, str2);

  printf("PID %d:\tanonymous %s, zero-backed %s\n", parpid, anon, zero);
  munmap(anon, 4096);
  munmap(zero, 4096);
  close(fd);
  return EXIT_SUCCESS;
}
