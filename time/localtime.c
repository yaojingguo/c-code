#include <time.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    time_t now = time(NULL);
    assert(now != -1);
    struct tm* t = localtime(&now);
    printf("year: %d, month: %d, day: %d\n", t->tm_year, t->tm_mon, t->tm_mday);
    printf("hour: %d, minute: %d, second: %d\n", t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}
