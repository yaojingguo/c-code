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

int main()
{
  int sockfd;
  struct sockaddr_in serv_addr;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    goto err;

  memset(&serv_addr, '0', sizeof(struct sockaddr_in));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(5000);
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) != 1)
    goto err;

  if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) != 0)
    goto err;

  int i;
  char buf[1024];
  while ((i = read(sockfd, buf, sizeof(buf) - 1)) > 0) {
    buf[i] = 0;
    printf("%s", buf);
  }
  if (i < 0)
    goto err;
  return 0;

err:
  perror(NULL);
  exit(EXIT_FAILURE);
}
