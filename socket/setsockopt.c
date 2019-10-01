#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <signal.h>
#include <stdio.h>

int main() {
    int sockfd;

    socklen_t optlen;
    size_t len;
    size_t t1, t2;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    optlen = sizeof(len);
    if (getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &len, &optlen) < 0) {
        perror(": getsockopt");
    }
    printf("receive buffer size = %ld\n", len);

    if (getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &len, &optlen) < 0) {
        perror(": getsockopt");
    }
    printf("send buffer size = %ld\n", len);

    if (getsockopt(sockfd, SOL_SOCKET, SO_RCVLOWAT, &len, &optlen) < 0) {
        perror(": getsockopt");
    }
    printf("rcv low watermark= %ld\n", len);

    if (getsockopt(sockfd, SOL_SOCKET, SO_SNDLOWAT, &len, &optlen) < 0) {
        perror(": getsockopt");
    }
    printf("snd low watermark = %ld\n", len);

    /*struct timeval tv;*/
    /*if (getsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &len, &tv) < 0) {*/
    /*    perror(": getsockopt");*/
    /*}*/
    /*printf("tv_sec: %d\n", tv.tv_sec);*/
    /*printf("tv_usec: %d\n", tv.tv_usec);*/


    t1 =1000000; t2 = sizeof(int);
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &t1, t2) < 0) {
        perror(": setsockopt");
    }
    optlen = sizeof(len);
    if (getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &len, &optlen) < 0) {
        perror(": getsockopt");
    }
    printf("modified receive buffer size = %ld\n", len);


    t1 = 2; t2 = sizeof(int);
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVLOWAT, &t1, t2) < 0) {
        perror(": setsockopt");
    }
    if (getsockopt(sockfd, SOL_SOCKET, SO_RCVLOWAT, &len, &optlen) < 0) {
        perror(": getsockopt");
    }
    printf("modified rcv low watermark= %ld\n", len);

    
    int max_size;
    socklen_t size = sizeof(int);
    if (getsockopt(sockfd, IPPROTO_TCP, TCP_MAXSEG, &max_size, &size) < 0) {
        perror(": getsockopt");
    }
    printf("maximum segment size: %d\n", max_size);
}








