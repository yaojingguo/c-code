#include <stdio.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <assert.h>

#define SEC 100000000L

int main(int argc, char *argv[]) {
    struct timespec value = {1548145150L, 447876025L}; 
    int result = clock_settime(CLOCK_REALTIME, &value);
    assert(result == 0);
    return 0;
}
