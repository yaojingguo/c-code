#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct tm tm;
    time_t t;

    if (strptime("6 Dec 2001 12:33:45", "%d %b %Y %H:%M:%S", &tm) == NULL) {
        perror("strptime error");
        return 1;
    }
        /* Handle error */;

    printf("year: %d; month: %d; day: %d;\n",
            tm.tm_year, tm.tm_mon, tm.tm_mday);
    printf("hour: %d; minute: %d; second: %d\n",
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("week day: %d; year day: %d\n", tm.tm_wday, tm.tm_yday);

    tm.tm_isdst = -1;      /* Not set by strptime(); tells mktime()
                              to determine whether daylight saving time
                              is in effect */
    t = mktime(&tm);
    if (t == -1)
        /* Handle error */;
    printf("seconds since the Epoch: %ld\n", (long) t);
        return 0;
}
