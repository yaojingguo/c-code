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
  struct servent * sv = getservbyname("http", "tcp");
  int i;

  printf("s_name: %s\n", sv->s_name);
  i = 0; 
  while (sv->s_aliases[i] != NULL) {
    printf("s_aliases[%d]: %s\n", i, sv->s_aliases[i]);
    i++;
  }





  //
  // struct servent {
  //     char  *s_name;       /* official service name */
  //     char **s_aliases;    /* alias list */
  //     int    s_port;       /* port number */
  //     char  *s_proto;      /* protocol to use */
  // }
  //
  // s_port is split into two parts: the lower short part and the higher short 
  // part in network order. Only the higher part is used. Port 80 in hex is 
  // 0x50. It is stored in memory as  the following diagram shows:
  //
  //            +----+
  // 0x00000000 | 00 |
  //            +----+
  // 0x00000001 | 50 |
  //            +----+
  // 0x00000002 | 00 |
  //            +----+
  // 0x00000003 | 00 |
  //            +----+
  //
  // So printf will print it as 0x00005000.
  printf("s_port: 0x%08X\n", sv->s_port);
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


