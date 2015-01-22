#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MYPORT "5000"
#define BACKLOG 10

int main(int argc, char *argv[]) {
  struct sockaddr_storage their_addr;
  socklen_t addr_size;
  struct addrinfo hints, *res;
  int sockfd, new_fd;

  memset(&hints, 0, sizeof(hints));
  // Use IPv4 or IPv6 whichever
  // hints.ai_family = AF_UNSPEC;
  hints.ai_family = AF_INET | AF_INET6;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  getaddrinfo(NULL, MYPORT, &hints, &res);

  sockfd = socket(res->ai_family, 
                  res->ai_socktype,
                  res->ai_protocol);
  bind(sockfd, res->ai_addr, res->ai_addrlen);
  listen(sockfd, BACKLOG);

  addr_size = sizeof(their_addr);
  while (1) {
    new_fd = accept(sockfd, 
        (struct sockaddr*) &their_addr,
        &addr_size);
    write(new_fd, "abc\n", 4);
  }

  close(new_fd);
  close(sockfd);
}
