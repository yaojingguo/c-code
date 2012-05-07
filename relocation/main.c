#include <stdio.h>

extern int no;
extern void foo(int);

int main(int argc, const char *argv[]) {
	foo(no);
	return 0;
}
