#include <stdio.h>

int main() {
	long long num = 2852126720000ll; // bigger that (2^31 - 1)
	printf("size: %d, value: %lld\n",	sizeof(num), num);
	return 0;
}
