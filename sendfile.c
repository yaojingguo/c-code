#include <sys/sendfile.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
  int ifd, ofd;
  char *fname[256];

  snprintf(fname, sizeof(fname), __FILE__"%d", getpid());
  unlink(fname);

  ifd = open(__FILE__, O_RDONLY, 0);
  if (ifd < 00) {
    printf("open() error: %s\n", strerror(errno));
    exit(1);
  }

  ofd = open(__FILE__"out", O_CREAT | O_RDWR | O_EXCL, S_IRUSR | S_IWUSR);
  if (ifd < 00) {
    printf("open() error: %s\n", strerror(errno));
    close(ifd);
    exit(1);
  }

  if (sendfile(ifd, ofd, 0, 10) != 10) {
    printf("sendfile() error: %s\n", strerror(errno));
    close(ifd);
    close(ofd);
    unlink(fname);
    exit(1);
  }

  close(ifd);
  close(ofd);
  unlink(fname);
  return 0;
}
