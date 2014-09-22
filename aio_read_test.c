#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <aio.h>

#define SIZE 111

int main() {
  char filename[256];
  unsigned char buf[SIZE];
  unsigned char check[SIZE];
  int fd;
  struct aiocb aiocb;
  int i;
  int err;
  int ret;

  snprintf(filename, sizeof(filename), __FILE__"_%d", getpid());
  unlink(filename);
  fd = open(filename, O_CREAT | O_RDWR | O_EXCL, S_IRUSR | S_IWUSR);
  if (fd == -1) {
    printf("open() error: %s\n", strerror(errno));
    exit(1);
  }

  for (i = 0; i < SIZE; i++)
    buf[i] = i;

  if (write(fd, buf, SIZE) != SIZE) {
    printf("write() error: %s\n", strerror(errno));
		goto ret;
  }

  memset(check, 0x00, SIZE);
  memset(&aiocb, 0, sizeof(struct aiocb));
  aiocb.aio_fildes = fd;
  aiocb.aio_buf = check;
  aiocb.aio_nbytes = SIZE;
  aiocb.aio_lio_opcode = LIO_WRITE;

  if (aio_read(&aiocb) == -1) {
    printf("aio_read() error: %s\n", strerror(errno));
		goto ret;
  }

  while ((err = aio_error (&aiocb)) == EINPROGRESS)
		;

  err = aio_error(&aiocb);
  ret = aio_return(&aiocb);

  if (err != 0) {
    printf("aio_error() error: %s\n", strerror(err));
		goto ret;
  }

  if (ret != SIZE) {
    printf("aio_return() error\n");
		goto ret;
  }

  for (i = 0; i < SIZE; i++) 
    if (buf[i] != check[i]) {
      printf(" read values are corrupted\n");
			goto ret;
    }
  printf("Test passed\n");

ret:
  close(fd);
  unlink(filename);
  return 0;
}
