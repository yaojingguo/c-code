#include <stdio.h>

int main(int argc, const char *argv[]) 
{
	int a = 0x67; // 0110 0111
	int b = 0xC5; // 1100 0101
								// 1010 0010
	printf("result: %x\n", a ^ b);
	return 0;
}
