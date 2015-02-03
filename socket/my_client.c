#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

#include "lib.h"


void info_sockaddr(struct sockaddr *sa)
{
  struct sockaddr_in * sain = (struct sockaddr_in *) sa;
  switch (sa->sa_family) {
    case AF_INET:
      printf("IPv4\n");
      printf("IP address: %08x\n", sain->sin_addr.s_addr);
      printf("Port number: %04x\n", sain->sin_port);
      break;
    case AF_INET6:
      printf("IPv6\n");
      break;
  }
}

void test_getpeername(int sockfd)
{
  socklen_t len;
  struct sockaddr_storage addr;
  char ipstr[INET6_ADDRSTRLEN];
  int port;

  len = sizeof(addr);
  // printf("0000\n");
  if (getpeername(sockfd, (struct sockaddr*) &addr, &len) != 0) 
    exit_failure();

  // printf("1111\n");

  if (addr.ss_family == AF_INET) { 
    struct sockaddr_in *s = (struct sockaddr_in*) &addr;
    port = ntohs(s->sin_port);
    // printf("1111\n")
    if (inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof(ipstr)) == NULL)
      exit_failure();
    // printf("2222\n");
  } else if (addr.ss_family == AF_INET6) {
    struct sockaddr_in6 *s = (struct sockaddr_in6*) &addr;
    port = ntohs(s->sin6_port);
    if (inet_ntop(AF_INET6, &s->sin6_addr, ipstr, sizeof(ipstr)) == NULL)
      exit_failure();
  } else {
    printf("Unsupported address family: %d", addr.ss_family);
    exit(EXIT_FAILURE);
  }
  printf("Peer IP address: %s\n", ipstr);
  printf("Peer port      : %d\n", port);
} 

void read_data(int sockfd)
{
  int i;
  char buf[1024];
  while ((i = read(sockfd, buf, sizeof(buf) - 1)) > 0) {
    buf[i] = 0;
    printf("%s", buf);
  }
  if (i < 0)
    exit_failure();
}

int main(int argc, char *argv[])
{
  int sockfd;
  struct sockaddr_in serv_addr;
  char *local_ip;

  if (argc < 2) 
    local_ip = "127.0.0.1";
  else
    local_ip = argv[1];

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    exit_failure();

  memset(&serv_addr, '0', sizeof(struct sockaddr_in));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(5000);

  if (inet_pton(AF_INET, local_ip, &serv_addr.sin_addr) != 1)
    exit_failure();

  printf("Local sockaddr\n");
  info_sockaddr((struct sockaddr* ) &serv_addr);
  p("Connnect");
  if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) != 0) 
    exit_failure();
  test_getpeername(sockfd);
  p("Read data");

  read_data(sockfd);

  return 0;

}
