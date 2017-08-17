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

int main(int argc, char *argv[])
{
  int sockfd = 0;
  char buf[1024];
  struct sockaddr_in serv_addr; 

  if (argc != 2) {
    printf("Usage: %s <ip of server> \n",argv[0]);
    return 1;
  } 

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("Error : Could not create socket \n");
    return 1;
  } 

  memset(&serv_addr, 0, sizeof(serv_addr)); 
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(5000); 
  if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
    perror("inet_pton error occured\n");
    return 1;
  } 

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error : Connect Failed \n");
    return 1;
  } 

  if (write(sockfd, "abc\n", 4) != 4) {
    perror("write error");
    return 1;
  }

  int copy;
  if ((copy = dup(sockfd)) == -1) {
    printf("Error: dup error\n");
    return 1;
  }

  int i = 0;
  memset(buf, 0,sizeof(buf));
  while ((i = read(sockfd, buf, sizeof(buf)-1)) > 0) {
    buf[i] = 0;
    if(fputs(buf, stdout) == EOF) {
      printf("Error : Fputs error\n");
    }
  } 

  if (i < 0) {
    printf("Read error \n");
  } 


  printf("Sleeping...\n");
  sleep(10 * 60);
  printf("Wake up");

  return 0;
}
