#include <stdio.h>

void pointer_init()
{
	int* p;
	int i = 10;
	// *p = i; // segmentation fault
	p = &i;
}

void pointer_size() {
	double *d_p;
	printf("double pointer size: %d\n", sizeof(d_p));
	printf("double size: %d\n", sizeof(*d_p));

	int *i_p;
	printf("int pointer size: %d\n", sizeof(i_p));
	printf("int size: %d\n", sizeof(*i_p));
}

int main(int argc, const char *argv[]) 
{
	pointer_init();
	pointer_size();
	return 0;
}
