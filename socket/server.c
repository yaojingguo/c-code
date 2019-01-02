#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 

    char sendBuff[1025];
    time_t ticks; 
    int reuse = 1;

    printf("socket...\n");
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket error:");
        exit(1);
    }

    printf("setsockopt...\n");
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
        perror("setsockopt error: ");
        exit(1);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000); 

    printf("bind...\n");
    if (bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind error:");
        exit(1);
    }

    printf("listen...\n");
    if(listen(listenfd, 10) == -1) {
        perror("listen error:");
        exit(1);
    }

    // Parent process
    // for (;;) {
    printf("accept...\n");
    if ((connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1) {
        perror("accept error:");
        exit(1);
    }

    printf("Write data\n");

    ticks = time(NULL);
    snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
    if (write(connfd, sendBuff, strlen(sendBuff)) == -1) {
        perror("write error:");
        exit(1);
    }

    close(connfd);
    //   sleep(1);
    // }
    return 1;
}
