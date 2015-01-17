#include <arpa/inet.h>
#include <stdio.h>
#include <assert.h>

/*uint32_t htonl(uint32_t hostlong);*/
/*uint16_t htons(uint16_t hostshort);*/
/*uint32_t ntohl(uint32_t netlong);*/
/*uint16_t ntohs(uint16_t netshort);*/

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

int main(void)
{
  test_short();
  /*uint16_t h_port;*/
  /*uint16_t n_port;*/

  /*h_port = 5000;*/
  /*n_port = htons(5000);*/
  /*printf("0x%x\n", n_port);*/

  /*if (n_port == 0x8813u)*/
  /*  printf("yes\n");*/
}
