#include <string.h>
#include <stdio.h>

void foo (char *bar)
{
   float My_Float = 10.5; // Addr = 0x0023FF4C
   char  c[28];           // Addr = 0x0023FF30

   // Will print 10.500000
   printf("My Float value = %f\n", My_Float);

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
       Memory map:
       @ : c allocated memory
       # : My_Float allocated memory

           *c                      *My_Float
       0x0023FF30                  0x0023FF4C
           |                           |
           @@@@@@@@@@@@@@@@@@@@@@@@@@@@####
      foo("my string is too long !!!!! XXXX");

   memcpy will put 0x1010C042 (little endian) in My_Float value.
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

   memcpy(c, bar, strlen(bar));  // no bounds checking...

   // Will print 96.031372
   printf("My Float value = %f\n", My_Float);
}

int main (int argc, char **argv)
{
   foo("my string is too long !!!!! \x10\x10\xc0\x42");
   return 0;
}
