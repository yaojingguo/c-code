#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

void test1()
{
  printf("u_short size: %d\n", sizeof(u_short));
  printf("u_long size: %d\n", sizeof(u_long));
  printf("struct sockaddr: %d\n", sizeof(struct sockaddr));
  printf("struct in_addr: %d\n", sizeof(struct in_addr));
  printf("struct sockaddr_in: %d\n", sizeof(struct sockaddr_in));
}

void test2()
{
  struct servent * sv = getservbyname("ftp", "tcp");
  int i;

  printf("s_name: %s\n", sv->s_name);
  i = 0; 
  while (sv->s_aliases[i] != NULL) {
    printf("s_aliases[%d]: %s\n", i, sv->s_aliases[i]);
    i++;
  }
  printf("s_port: %x, %x\n", sv->s_port, ntohl(sv->s_port));
  printf("s_proto: %s\n", sv->s_proto);
}

void test3()
{
  in_addr_t addr = inet_addr("171.64.64.64");
  printf("in_addr_t: %X\n", addr);	
}

void test4()
{
  printf("%x\n", 80);
  printf("%x\n", htonl(80));
}

int main() 
{
  test1();
  test2();
  test3();
  test4();
}


