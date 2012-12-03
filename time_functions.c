#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
// Compile using "gcc time_functions.c -lrt"
void test0()
{
	time_t time0;
	time0 = time(NULL);

	// sleep 5 seconds
	if (usleep(5 * 1000 * 1000) != 0)
		perror(NULL);

	time_t time1;
	time1 = time(NULL);

	printf("sizeof(time_t): %d, %d\n", sizeof(time_t), sizeof(long int));
	printf("time0: %ld, time1: %ld, diff: %ld\n", time0, time1, time1 - time0);
}

void test1()
{
	struct timespec now;
	if (clock_gettime(CLOCK_REALTIME, &now) != 0)
		perror(NULL);
	printf("seconds: %ld, nanoseconds: %ld\n", now.tv_sec, now.tv_nsec);
}

int main(int argc, const char *argv[]) 
{
	test0();
	test1();
	return 0;
}
