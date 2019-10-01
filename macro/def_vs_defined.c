#include <stdio.h>

/* #define HDR */

int main(int argc, char *argv[]) {

#if defined(HDR)
    printf("HDR is defined.\n");
#endif

#ifdef HDR
    printf("HDR is defined.\n");
#endif
    
    return 0;
}
