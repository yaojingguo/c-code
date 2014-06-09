#include <stdio.h>

int main()
{
	printf("%10s\n", "abc");
	printf("%.s\n", "abc");
	printf("%2d\n", 19999);
	printf("%.6d\n", 12345);
	printf("%a\n", 8.5);
	printf("%a\n", 1024 * 1024);
	float a = 0.1;
	printf("%.17f\n", a);
}
