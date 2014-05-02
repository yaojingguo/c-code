#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main(int argc, const char *argv[]) 
{
  int segment_id;
  char* shared_memory;
  struct shmid_ds shmbuffer;
  int segment_size;
  const int shared_segment_size = 0x6400;

  // Allocate
  segment_id = shmget(IPC_PRIVATE, shared_segment_size,
                      IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
  shared_memory = (char*) shmat(segment_id, 0, 0);
  printf("shared memory attached at address %p\n", shared_memory);

  // Attach
  shmctl(segment_id, IPC_STAT, &shmbuffer);
  segment_size = shmbuffer.shm_segsz;
  printf("segment size: %d\n", segment_size);
  sprintf(shared_memory, "Hello, world.");
  shmdt(shared_memory);

  // Reattach
  shared_memory = (char*) shmat(segment_id, (void*) 0x5000000, 0);
  printf("shared memory attached at address %p\n", shared_memory);
  printf("%s\n", shared_memory);
  shmdt(shared_memory);

  // Deallocate
  shmctl(segment_id, IPC_RMID, 0);

  return 0;
}
