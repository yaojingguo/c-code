#include <pthread.h>
#include <assert.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>

// Use "gcc -pthread pthread_cond_timedwait.c -lrt" to compile.

pthread_mutex_t m;
pthread_cond_t c;

void
add_timespec(const struct timespec* a, 
    int b, 
    struct timespec *result)
{
	// convert to millisec, add timeout, convert back
	result->tv_sec = a->tv_sec + b/1000;
	result->tv_nsec = a->tv_nsec + (b % 1000) * 1000000;
	assert(result->tv_nsec >= 0);
	while (result->tv_nsec > 1000000000){
		result->tv_sec++;
		result->tv_nsec-=1000000000;
	}
}

int main(int argc, const char *argv[]) 
{
  assert(pthread_mutex_init(&m, NULL) == 0);
  assert(pthread_cond_init(&c, NULL) == 0);
  int timeout = 3000 * 10;
  struct timespec now, deadline; 
  clock_gettime(CLOCK_REALTIME, &now);
  add_timespec(&now, timeout, &deadline); 
  int ret = pthread_cond_timedwait(&c, &m, &deadline);
  if (ret = ETIMEDOUT) 
    printf("timeout: %d\n", ret);
  assert(pthread_cond_destroy(&c) == 0);
  assert(pthread_mutex_destroy(&m) == 0);
  return 0;
}
