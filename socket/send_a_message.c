#include <stdio.h>	//printf
#include <string.h>	//strlen
#include <sys/socket.h>	//socket
#include <arpa/inet.h>	//inet_addr
#include <stdlib.h>
#include <unistd.h>

int main(int argc , char *argv[]) {
  int sock;
  struct sockaddr_in server;

  //Create socket
  sock = socket(AF_INET , SOCK_STREAM , 0);
  if (sock == -1) {
    perror("Could not create socket");
    exit(1);
  }
  printf("Socket created\n");

  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons(1234);

  //Connect to remote server
  if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
    perror("connect failed. Error");
    exit(1);
  }
  printf("Connected\n");

  //keep communicating with server
  const char* message = "hi\n";
  if( send(sock , message , strlen(message) , 0) < 0) {
    puts("Send failed");
    return 1;
  }
  printf("message sent\n");

  close(sock);
  return 0;
}
