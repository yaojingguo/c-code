#include <stdio.h>

struct foo {
	int a;
	int b;
	int c;
};

static void info(struct foo *f)
{
	printf("a: %d, b: %d, c: %d\n", f->a, f->b, f->c);
}

int main()
{
	struct foo f = {
		.a = 10,
		.b = 20,
	};
	info(&f);

	return 0;
}
