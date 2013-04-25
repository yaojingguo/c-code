#include <stdio.h>
#include <assert.h>

void swap(int *a, int *b) 
{
    printf("swap: %d, %d\n", *a, *b);
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
    } 
}


// A[p...i] < A[r]
// A[i+1...j-1] >= A[r]
int partition(int A[], int p, int r)
{
    printf("p-------------\n");
    int i;
    int j;
    i = p - 1;
    for (j = p; j < r; j++) 
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

void test(int A[], int size, int no) 
{
    printf("======== test%d\n", no);
    info(A, 0, size-1);
    printf("------------\n");
    quicksort(A , 0, size-1);
    verify(A, 0, size-1);
}
void test1() 
{
    int array[] = {1, 7, 2, 10};
    test(array, 4, 1);
}

void test2() 
{
    int array[] = {1, 10};
    test(array, 2, 2);
}

// Quicksort is unstable. For example, the original array is  5 5_ 4. The array 
// after quicksorting is 4 5_ 5.
void test3()
{
    int array[] = {5, 5, 4};
    test(array, 3, 3);
}

int main(int argc, const char *argv[]) 
{
    // test1();
    // test2();
    test3();
}

