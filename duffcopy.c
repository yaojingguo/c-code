#include <stdio.h>
#include <string.h>

void duffcopy(char *to, char* from, int count) 
{
  int n = (count + 7) / 8;
  switch (count % 8) {    
    case 0:                       
      do {                 
        *to++ = *from++;   
        case 7:      *to++ = *from++;   
        case 6:      *to++ = *from++;   
        case 5:      *to++ = *from++;   
        case 4:      *to++ = *from++;   
        case 3:      *to++ = *from++;   
        case 2:      *to++ = *from++;   
        case 1:      *to++ = *from++;   
      } while (--n > 0);     
  }                             
}

int main(int argc, char *argv[])
{
  char *from = "1234567890123456789"; 
  char to[20];

  duffcopy(to, from, strlen(from) + 1);

  printf("from: %s\n", from);
  printf("to:   %s\n", to);

  return 0;
}
