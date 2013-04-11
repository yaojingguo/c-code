#include <stdio.h>
// Bubble sort with optimization as suggested by 
// http://en.wikipedia.org/wiki/Bubble_sort
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int A[], int n) {
    int newn;
    int i;
    int pass;

    pass = 0;

    do {
        newn = 0;
        for (i = 1; i <= n-1; i++) 
            if (A[i-1] > A[i]) {
                swap(&A[i-1], &A[i]);   
                newn = n;
            }
        pass++;
    } while (newn > 0);
    printf("pass: %d\n", pass);
}

void info_array(int A[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("A[%d] = %d\n", i, A[i]);
}

void test1() {
    int A[] = {1, 3, 10, 1};
    bubble_sort(A, 4);
    info_array(A, 4);
}

void test2() {
    int A[] = {6, 5, 1, 8, 9, 10};
    bubble_sort(A, 6);
    info_array(A, 6);
}

int main(int argc, const char *argv[]) {
    test1();
    test2(); 
    return 0;
}
