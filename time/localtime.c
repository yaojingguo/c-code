#include <time.h>
#include <stdio.h>
#include <assert.h>

void info(struct tm* t) {
    printf("  year: %d, month: %d, day: %d\n", t->tm_year, t->tm_mon, t->tm_mday);
    printf("  hour: %d, minute: %d, second: %d\n", t->tm_hour, t->tm_min, t->tm_sec);
    printf("  tm_isdst: %d\n", t->tm_isdst);
}

int main(int argc, char *argv[]) {
    time_t now = time(NULL);
    assert(now != -1);
    struct tm* local = localtime(&now);
    printf("localtime: \n");
    info(local);
    struct tm* gm = gmtime(&now);
    printf("gmtime: \n");
    info(gm);
    return 0;
}
