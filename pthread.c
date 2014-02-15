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

int main(int argc, const char *argv[]) 
{
  pthread_t th; 
  assert(pthread_mutex_init(&lock, NULL) == 0);
  assert(pthread_mutex_lock(&lock) == 0);
  assert(pthread_create(&th, NULL, run, NULL) == 0);
  sleep(100);
  assert(pthread_mutex_unlock(&lock) == 0);
  return 0;
}
