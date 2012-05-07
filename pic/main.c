#include <stdio.h>

extern int my_func(int no);
extern void var();

int main(int argc, const char *argv[]) {
	int i;
	
	i = 0;
	my_func(i);
	bar();
		
	return 0;
}
