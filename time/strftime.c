#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    time_t t;
    struct tm *tmp;
    char buf1[16];
    char buf2[128];

    time(&t);
    tmp = localtime(&t);

    char* fmt = "time and date: %r, %a %b %d, %Y, %Z";

    if (strftime(buf1, 16, fmt, tmp) == 0)
        printf("buffer length 16 is too small\n");
    else
        printf("%s\n", buf1);

    if (strftime(buf2, 128, fmt, tmp) == 0)
        printf("buffer length 128 is too small\n");
    else
        printf("%s\n", buf2);

    return 0;
}
