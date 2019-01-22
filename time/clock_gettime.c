#include <stdio.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>

#define SEC 100000000L

int main(int argc, char *argv[]) {
    struct timespec start, finish;
    clock_gettime(CLOCK_REALTIME, &start);

    // chew up some CPU time
    int i,j; for (i=0,j=0; i<100000000; i++) { j+=i*i; }    

    clock_gettime(CLOCK_REALTIME, &finish);
    long seconds = finish.tv_sec - start.tv_sec;
    long ns = finish.tv_nsec - start.tv_nsec;

    if (start.tv_nsec > finish.tv_nsec) {
        --seconds;
        ns += SEC;
    }

    printf("seconds with ns: %ld\n", seconds);
    printf("nanoseconds: %ld\n", ns);
    printf("total seconds: %e\n", (double) seconds + (double)ns/(double)SEC);

    return 0;
}
