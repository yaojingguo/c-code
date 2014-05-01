//process2.cc

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define MAX_SHM_SIZE 1024*1024

int main()
{
  const char *name = "/home/jing/code/work/IPC";
  int i = 1;

  key_t key = ftok(name, i);
  if(-1 == key)
  {
    perror("ftok");
    return 1;
  }

  int shm_id = shmget(key, MAX_SHM_SIZE, IPC_CREAT|0666);
  if(-1 == shm_id) {
    perror("shmget");
    return 1;
  }

  char *p = (char *)shmat(shm_id, 0, 0);
  if((void *)-1 == (void *)p) {
    perror("shmat");
    return 1;
  }

  //read memory
  int size;
  memcpy(&size, p, 4);
  char buffer[1024] = {'\0'};
  memcpy(buffer, p+4, size);

  printf("%s", buffer);
  shmdt(p);

  return 0;
}
