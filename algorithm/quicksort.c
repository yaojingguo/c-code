#include <stdio.h>
#include <assert.h>

void swap(int *a, int *b) 
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int A[], int p, int r)
{
    int q;
    if (p < r) {
        q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    } else {
        printf("p=%d, r=%d\n", p, r);
    }
}


// A[p...i] < A[r]
// A[i+1...j-1] >= A[r]
int partition(int A[], int p, int r)
{
    int i;
    int j;
    i = p - 1;
    for (j = p; j < r; j++) 
        /*if (A[j] < A[r]) {*/
        if (A[j] <= A[r]) {
            i++;
            swap(&A[i], &A[j]);
        }
    swap(&A[i+1], &A[r]);
    return i+1;
}

void info(int A[], int p, int r) 
{
    int i;
    for (i = p; i <= r; i++)
        printf("A[%d]=%d\n", i, A[i]);
}

void verify(int A[], int p, int r) 
{
    int i;
    for (i = p; i <= r; i++) {
        if (i <= r)
            assert(A[p] <= A[p+1]);
        printf("A[%d]=%d\n", i, A[i]);
    }
}
void test1() 
{
    printf("======== test1\n");
    int array[] = {1, 7, 2, 10};
    info(array, 0, 3);
    quicksort(array, 0, 3);
    verify(array, 0, 3);
}

void test2() 
{
    printf("======== test2\n");
    int array[] = {1, 10};
    info(array, 0, 1);
    quicksort(array, 0, 1);
    verify(array, 0, 1);
}

void test3() 
{
    printf("======== test3\n");
    int array[] = {7, 2};
    info(array, 0, 1);
    quicksort(array, 0, 1);
    verify(array, 0, 1);
}

int main(int argc, const char *argv[]) 
{
    test1();
    test2();
    test3();
}

