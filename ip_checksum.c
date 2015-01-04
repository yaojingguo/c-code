#include <stdio.h>

/*
 **************************************************************************
Function: ip_sum_calc
Description: Calculate the 16 bit IP sum.
 ***************************************************************************
 */
typedef unsigned short u16;
typedef unsigned long u32;

u16 ip_sum_calc(u16 len_ip_header, u16 buff[])
{
  u16 word16;
  u32 sum=0;
  u16 i;

  // make 16 bit words out of every two adjacent 8 bit words in the packet
  // and add them up
  for (i=0;i<len_ip_header;i=i+2){
    word16 =((buff[i]<<8)&0xFF00)+(buff[i+1]&0xFF);
    sum = sum + (u32) word16;	
  }

  // take only 16 bits out of the 32 bit sum and add up the carries
  while (sum>>16)
    sum = (sum & 0xFFFF)+(sum >> 16);

  // one's complement the result
  sum = ~sum;

  return ((u16) sum);
}

int main()
{
  printf("u16 size: %ld\n", sizeof(u16));
}
