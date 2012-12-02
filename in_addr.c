#include <stdio.h>
#include <memory.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
// [> Internet address.  <]
// typedef uint32_t in_addr_t;
// struct in_addr
//   {
//     in_addr_t s_addr;
//   };


void test1()
{
  struct hostent *host_entry;
  struct in_addr ip;

  host_entry = gethostbyname("localhost");
  bcopy(host_entry->h_addr, &(ip.s_addr), host_entry->h_length);

  char* str = inet_ntoa(ip);
  printf("ip: %s\n", str);
}

void test2()
{
  struct in_addr ip = { 0x11223344u };
  printf("fake: %s", inet_ntoa(ip));
}

// [> Structure describing an Internet socket address.  <]
// struct sockaddr_in
//   {
//     __SOCKADDR_COMMON (sin_);
//     in_port_t sin_port;			[> Port number.  <]
//     struct in_addr sin_addr;		[> Internet address.  <]

//     [> Pad to size of `struct sockaddr'.  <]
//     unsigned char sin_zero[sizeof (struct sockaddr) -
//          __SOCKADDR_COMMON_SIZE -
//          sizeof (in_port_t) -
//          sizeof (struct in_addr)];
//   };

// [> Ditto, for IPv6.  <]
// struct sockaddr_in6
//   {
//     __SOCKADDR_COMMON (sin6_);
//     in_port_t sin6_port;	[> Transport layer port # <]
//     uint32_t sin6_flowinfo;	[> IPv6 flow information <]
//     struct in6_addr sin6_addr;	[> IPv6 address <]
//     uint32_t sin6_scope_id;	[> IPv6 scope-id <]
//   };

// #define	__SOCKADDR_COMMON(sa_prefix) \
//   sa_family_t sa_prefix##family
void test3()
{
  struct sockaddr_in server_socket_address;
}

int main(int argc, const char *argv[]) 
{
  test1();
  test2();
  return 0;
}
