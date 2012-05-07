#include <stdio.h>

extern int increment(int no);

int main(int argc, const char *argv[]) {
	int i;
	
	i = 100;
	i = increment(i);
	printf("i: %d\n", i);
		
	return 0;
}
