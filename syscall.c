#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

void api() {
  printf("process id: %d\n", getpid());
}

void wrapper() {
  pid_t pid;
  pid = syscall(SYS_gettid);
  printf("process id: %d\n", pid);
}

int main() {
  api();
  wrapper();
}
