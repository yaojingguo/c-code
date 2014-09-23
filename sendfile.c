#include <sys/sendfile.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int ifd, ofd;
  char fname[256];

  snprintf(fname, sizeof(fname), __FILE__"%d", getpid());
  unlink(fname);

  ifd = open(__FILE__, O_RDONLY);
  if (ifd < 0) {
    printf("open() error: %s\n", strerror(errno));
    exit(1);
  }

  ofd = open(fname, O_CREAT | O_RDWR | O_EXCL, S_IRUSR | S_IWUSR);
  if (ofd < 0) {
    printf("open() error: %s\n", strerror(errno));
    close(ifd);
    exit(1);
  }

  if (sendfile(ofd, ifd, 0, 10) != 10) {
    printf("sendfile() error: %s\n", strerror(errno));
    close(ifd);
    close(ofd);
    unlink(fname);
    exit(1);
  }

  printf("Test passed\n");
  close(ifd);
  close(ofd);
  unlink(fname);
  return 0;
}
