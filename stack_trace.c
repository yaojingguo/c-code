#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// Use "gcc -g -rdynamic stack_trace.c -o stack_trace" to compile. For 
// generating stack traces when C++ programs crash, refer to 
// http://stackoverflow.com/questions/77005/how-to-generate-a-stacktrace-when-my-gcc-c-app-crashes
void bar() 
{ 
  void *array[10];
  size_t size;
  size = backtrace(array, 10);
  backtrace_symbols_fd(array, 
                       size, 
                       STDERR_FILENO);
}

void foo() 
{ 
  int i;
  bar(); 
  i++;
}

int main(int argc, char **argv) 
{
  foo(); 
}
