#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  u_short port;                /* user specified port number */
  char *addr;                  /* will be a pointer to the address */
  struct sockaddr_in address;  /* the libc network address data structure */
  short int sock = -1;         /* file descriptor for the network socket */
  fd_set fdset;
  struct timeval tv;

  if (argc != 3) {
    fprintf(stderr, "Usage %s <port_num> <address>\n", argv[0]);
    return EXIT_FAILURE;
  }

  port = atoi(argv[1]);
  addr = argv[2];

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr(addr); /* assign the address */
  address.sin_port = htons(port);            /* translate int2port num */

  sock = socket(AF_INET, SOCK_STREAM, 0);
  fcntl(sock, F_SETFL, O_NONBLOCK);

  connect(sock, (struct sockaddr *)&address, sizeof(address));

  FD_ZERO(&fdset);
  FD_SET(sock, &fdset);
  tv.tv_sec = 10;             /* 10 second timeout */
  tv.tv_usec = 0;

  if (select(sock + 1, NULL, &fdset, NULL, &tv) == 1) {
    int so_error;
    socklen_t len = sizeof so_error;

    getsockopt(sock, SOL_SOCKET, SO_ERROR, &so_error, &len);

    if (so_error == 0) {
      printf("%s:%d is open\n", addr, port);
    } else {
      printf("%s:%d is not open\n", addr, port);
    }
  }

  close(sock);
  return 0;
}
