#include <arpa/inet.h>
#include <stdio.h>
#include <assert.h>

/*uint32_t htonl(uint32_t hostlong);*/
/*uint32_t ntohl(uint32_t netlong);*/

void test_short()
{
  uint16_t h_port;
  uint16_t n_port;
  h_port  = 5000u;
  assert(h_port == 0x1388u);
  n_port = htons(h_port);
  assert(n_port == 0x8813u);
  assert(ntohs(n_port) == h_port);
}

void test_int()
{
  uint32_t h_ip;
  uint32_t n_ip;

  h_ip = 0x01020304u;
  n_ip = htonl(h_ip);
  assert(n_ip == 0x04030201u);
  assert(ntohl(n_ip) == h_ip);
}

void test_inet_ntop()
{
}

int main(void)
{
  test_short();
  test_int();
}
