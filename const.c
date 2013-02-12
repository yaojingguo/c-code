#include <stdio.h>

/*
 * const data pointed by the pointer.
 */
void constData(const char *arg) 
{
    // can't be compiled
    // *arg = 'A';

    arg = "A";
}

/*
 * const pointer.
 */
void constPointer(char * const  p)
{
    // can't be compiled
    // p = "A";

    *p = 'A';
}

/*
 * argv is a pointer array. The pointers in the array are const.
 */
void constPointerArray(char * const argv[]) 
{
    // can't be compiled
    // argv[0] = "A";
    
    *(argv[0]) = 'x';
    argv = NULL;
}

int main(int argc, const char *argv[]) 
{
    //
    // *(argv[0]) = 'a';
    // argv

    //
    char str1[] = "abc";
    char str2[] = "123";
    char *pp[2];
    *pp = str1;
    *(pp+1) = str2;

    constData(str1);
    printf("%s\n", str1);

    constPointer(str1);
    printf("%s\n", str1);

    // constPointerArray(pp);
    printf("%s\n", *pp);
    printf("%s\n", *(pp+1));

    return 0;
}
