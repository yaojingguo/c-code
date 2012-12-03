#include <stdio.h>

int main()
{
	printf("Begin\n");
#if 0
	printf("Wrong if you see this message.\n");
#endif
	printf("End\n");

	printf("Begin\n");
#if 1
	printf("Right if you see this message.\n");
#endif
	printf("End\n");
}
