#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, const char *argv[]) 
{
	int h, l;

	h = 0x11223344;
	l = htonl(h);
	printf("host byte order: 0X%8x\n", h);			// little endian on Linux x86
	printf("network byte order: 0X%8x\n", l);   // big endian

	return 0;
}
