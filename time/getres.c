
#include <stdio.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>

#define SEC 100000000L

int main(int argc, char *argv[]) {
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    printf("sec: %ld\n", spec.tv_sec);
    printf("nsec: %ld\n", spec.tv_nsec);
    return 0;
}
