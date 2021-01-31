#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  int all;
  char *work_args[] = {NULL};

  all = open("all", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

  dup2(all, STDOUT_FILENO);
  dup2(all, STDERR_FILENO);

  close(all);

  execvp("./work", work_args);
}

