/*
 * Write a random number between 0 and 999 to the shm every 1 second.
 */
#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<error.h>
int main(){
	int shm_id;
	int *share;
	int num;
	srand(time(NULL));
	shm_id = shmget(9999, getpagesize(), IPC_CREAT | 0600);
	if(shm_id == -1){
		perror("shmget()");
	}
	share = (int *)shmat(shm_id, 0, 0);
  if (share == ((int*) -1)) {
    perror("shmat");
  }
	while (1) {
		num = random() % 1000;
		*share = num;
		printf("write a random number %d\n", num);
		sleep(1);
	}
	return 0;
}
