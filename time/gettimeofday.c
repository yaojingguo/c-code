#include <sys/time.h>
#include <stdio.h>
#include <assert.h>

unsigned long get_time();

int main(int nargs, char **args) {
  struct timeval tv;
  struct timezone tz;
  assert(gettimeofday(&tv, &tz) == 0);
  printf("seconds: %ld, microseconds: %d\n", tv.tv_sec, tv.tv_usec);
  printf("tz_minuteswest: %d\n", tz.tz_minuteswest);
  printf("tz_dsttime: %d\n", tz.tz_dsttime);
}
