#include <stdio.h>
#include <pthread.h>

int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg)
{
  return 0;
}

int main()
{
	if (pthread_create)
	{
		printf("This is multi-thread version!\n");
	}
	else
	{
		printf("This is single-thread version!\n");
	}
	return 0;
}