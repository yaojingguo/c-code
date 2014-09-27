#include <stdio.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define N 4

int main()
{
  char fname[256];
  int fd;
  char foo[] = "foo";
  char bar[] = "bar";
  struct iovec iov[2] = {
    { foo, N },
    { bar, N },
  };

  snprintf(fname, sizeof(fname), __FILE__"%d", getpid());
  unlink(fname);
  fd = open(fname, 
            O_CREAT | O_RDWR | O_EXCL,
            S_IRUSR | S_IWUSR);
  if (fd < 0) {
    printf("open() error: %s\n", strerror(errno));
    exit(1);
  }

  if (writev(fd, iov, 2) != 2*N) {
    printf("writev error: %s\n", strerror(errno));
    goto fail;
  }

  if (lseek(fd, 0, SEEK_SET) != 0) {
    printf("lseek error: %s\n", strerror(errno));
    goto fail;
  }
  memset(iov[0].iov_base, 0x00, N);
  memset(iov[1].iov_base, 0x00, N);

  int cnt;
  cnt = readv(fd, iov, 2); 
  printf("cnt: %d\n", cnt);
  printf("foo is %s\n", (char*) iov[0].iov_base);
  printf("bar is %s\n", (char*) iov[1].iov_base);

  if (cnt != 2*N) {
    printf("readv() error: %s\n", strerror(errno));
    goto fail;
  }

  goto success;

fail:
  unlink(fname);
  close(fd);
  exit(1);

success:
  printf("Test passed\n");
  unlink(fname);
  close(fd);
  return 0;
}
