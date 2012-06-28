#include <stdio.h>

int* func()
{
	return (int*) 10;
}

int main(int argc, const char *argv[]) 
{
	func()++;	// error: lvalue required as increment operand
	return 0;
}
