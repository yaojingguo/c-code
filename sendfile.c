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
  int cnt;
  int ifd, ofd;
  char fname[256];
  char buf[11] = { 0 };

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
    goto fail;
  }

  if (lseek(ofd, 0, SEEK_SET) != 0) {
    printf("lseek error: %s\n", strerror(errno));
    goto fail;
  }

  cnt = read(ofd, buf, 10);
  printf("read %d characters: %s\n", cnt, buf);
  if (cnt != 10) {
    printf("read() error: %s\n", strerror(errno));
    goto fail;
  }
  printf("Test passed\n");
  close(ifd);
  close(ofd);
  unlink(fname);
  return 0;

fail:
  close(ifd);
  close(ofd);
  unlink(fname);
  exit(1);
}
