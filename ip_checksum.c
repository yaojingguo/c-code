#include <stdio.h>

typedef unsigned short u16;
typedef unsigned int u32;

u16 ip_sum_calc(u16 len_ip_header, u16 buff[])
{
  u16 word16;
  u32 sum=0;
  u16 i;

  for (i = 0; i < len_ip_header; i++) {
    printf("0x%04x\n", buff[i]);
    sum = sum + (u32) buff[i];	
  }

  // take only 16 bits out of the 32 bit sum and add up the carries
  while (sum >> 16)
    sum = (sum & 0xFFFF) + (sum >> 16);

  // one's complement the result
  sum = ~sum;

  return ((u16) sum);
}

/*
13:50:36.947842 IP (tos 0x0, ttl 64, id 17989, offset 0, flags [DF], proto UDP (17), length 56)
    127.0.0.1.4445 > 127.0.0.1.54279: [bad udp cksum 0xfe37 -> 0x7e2b!] UDP, length 28
	0x0000:  4500 0038 4645 4000 4011 f66d 7f00 0001  E..8FE@.@..m....
	0x0010:  7f00 0001 115d d407 0024 fe37 5375 6e20  .....]...$.7Sun.
	0x0020:  4a61 6e20 3034 2031 333a 3530 3a33 3620  Jan.04.13:50:36.
	0x0030:  4353 5420 3230 3135                      CST.2015
*/
void udp()
{
  u16 buff[] = { 0x7f00, 0x0001, 0x7f00, 0x0001, 0x0011, 0x0024,
                 0x115d, 0xd407, 0x0024, 0x0000, 0x5375, 0x6e20,
                 0x4a61, 0x6e20, 0x3034, 0x2031, 0x333a, 0x3530, 0x3a33, 0x3620,
                 0x4353, 0x5420, 0x3230, 0x3135                   
  };
  u16 length = 24;
  // 0x7e2b
  printf("UDP checksum: 0x%04x\n", ip_sum_calc(length, buff));
}

void ip()
{
  // IP header: 4500 0038 4645 4000 4011 f66d 7f00 0001 7f00 0001
  u16 buff[] = {0x4500, 0x0038, 0x4645, 0x4000, 0x4011, 0x0000, 0x7f00, 0x0001, 0x7f00, 0x0001};
  u16 len_ip_header = 10;
  // 0xf66d
  printf("IP checksum: 0x%04x\n", ip_sum_calc(len_ip_header, buff));
}

int main()
{
  udp();
  ip();
}
