#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>

// During pthread_mutex_lock, the thread is in Sl+ state.
pthread_mutex_t lock;

void* run(void* p)
{
  printf("trying to lock...\n");
  assert(pthread_mutex_lock(&lock) == 0);
  assert(pthread_mutex_unlock(&lock) == 0);
  printf("unlocked\n");
}

void test_pthread_state()
{
  pthread_t th; 
  assert(pthread_mutex_init(&lock, NULL) == 0);
  assert(pthread_mutex_lock(&lock) == 0);
  assert(pthread_create(&th, NULL, run, NULL) == 0);
  sleep(100);
  assert(pthread_mutex_unlock(&lock) == 0);
}


// int pthread_cond_timedwait(pthread_cond_t *restrict cond,
//     pthread_mutex_t *restrict mutex,
//     const struct timespec *restrict abstime);
// int pthread_cond_wait(pthread_cond_t *restrict cond,
//     pthread_mutex_t *restrict mutex);
// int pthread_cond_destroy(pthread_cond_t *cond);
// int pthread_cond_init(pthread_cond_t *restrict cond,
//     const pthread_condattr_t *restrict attr);
// int pthread_cond_broadcast(pthread_cond_t *cond);
// int pthread_cond_signal(pthread_cond_t *cond);

int main(int argc, const char *argv[]) 
{
  return 0;
}
