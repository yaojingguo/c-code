#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct time_t now;
    struct tm* break_down = localtime(&now);
    return 0;
}
