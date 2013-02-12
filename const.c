#include <stdio.h>

// The position of const keyword decides what is is const. If const is before 
// *, the data pointed by the pointer is const. Otherwise, the pointer itself 
// is const. Data is const:
//  1) const char * arg
//  2) char const * arg
// Pointer is const: char * const arg

/*
 * const data pointed by the pointer.
 */
void constData1(const char *arg) 
{
    // can't be compiled
    // *arg = 'A';

    arg = "A";
}
void constData2(char const *arg) 
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
    // *(argv[0]) = 'a'; // wont compile
    argv[0] = "A";
    argv = NULL;

    char str1[] = "abc";
    char str2[] = "123";
    char *pp[2];
    *pp = str1;
    *(pp+1) = str2;

    constData1(str1);
    printf("%s\n", str1);

    constData2(str1);
    printf("%s\n", str1);

    constPointer(str1);
    printf("%s\n", str1);

    constPointerArray(pp);
    printf("%s\n", *pp);
    printf("%s\n", *(pp+1));

    return 0;
}
