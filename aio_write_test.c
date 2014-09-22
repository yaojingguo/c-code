/*
 * Copyright (c) 2004, Bull SA. All rights reserved.
 * Created by:  Laurent.Vivier@bull.net
 * This file is licensed under the GPL license.  For the full content
 * of this license, see the COPYING file at the top level of this
 * source tree.
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <aio.h>

#define BUF_SIZE 512

int main() {
  char filename[256];
  char buf[BUF_SIZE];
  char check[BUF_SIZE+1];
  int fd;
  struct aiocb aiocb;
  int err;
  int ret;

  snprintf(filename, sizeof(filename), __FILE__"_%d", getpid());
  unlink(filename);
  fd = open(filename, O_CREAT | O_RDWR | O_EXCL, S_IRUSR | S_IWUSR);
  if (fd == -1) {
    printf( "open() error: %s\n", strerror(errno));
    exit(1);
  }

  memset(buf, 0xaa, BUF_SIZE);
  memset(&aiocb, 0, sizeof(struct aiocb));
  aiocb.aio_fildes = fd;
  aiocb.aio_buf = buf;
  aiocb.aio_nbytes = BUF_SIZE;

  if (aio_write(&aiocb) == -1) {
    printf("aio_write() error: %s\n", strerror(errno));
		goto ret;
  }

  while (aio_error (&aiocb) == EINPROGRESS)
		;

  err = aio_error(&aiocb);
  ret = aio_return(&aiocb);

  if (err != 0) {
    printf ("aio_error() error: %s\n", strerror(err));
		goto ret;
  }

  if (ret != BUF_SIZE) {
    printf( " Error at aio_return()\n");
    close(fd);
    exit(2);
  }

  /* check the values written */

  if (lseek(fd, 0, SEEK_SET) == -1) {
    printf( " Error at lseek(): %s\n",
           strerror(errno));
    close(fd);
    exit(2);
  }

  /* we try to read more than we wrote to be sure of the size written */

  check[BUF_SIZE] = 1;
  if (read(fd, check, BUF_SIZE + 1) != BUF_SIZE) {
    printf( " Error at read(): %s\n",
           strerror(errno));
    close(fd);
    exit(2);
  }

  if ( check[BUF_SIZE] != 1) {
    printf( " Buffer overflow\n");
    close(fd);
    exit(2);
  }

  if (memcmp(buf, check, BUF_SIZE)) {
    printf( " Bad value in buffer\n");
    close(fd);
    exit(2);
  }
	printf("Test passed\n");

ret:
	unlink(filename);
  close(fd);
  return 0;
}
