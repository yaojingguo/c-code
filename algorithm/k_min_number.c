#include <stdio.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxify(int A[], int size, int top) 
{
    int left;
    int right;
    int large;
    large = top;
    left = 2 * (top + 1) - 1;
    if (left < size && A[left] > A[large]) 
        large = left;
    right = 2 * (top + 1);
    if (right < size && A[right] > A[large]) 
        large = right;
    if (large != top) {
        swap(&A[top], &A[large]);
        maxify(A, size, large);
    }
}

void build_heap(int A[], int size) 
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
        maxify(A, size, i);
}

void heap_sort(int A[], int size) {
    build_heap(A, size);
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\n", A[0]);
        A[0] = A[size - i - 1];
        maxify(A, size -i - 1, 0);
    }
}

void k_min(int A[], int size, int k) 
{
    build_heap(A, k + 1);
    int i;
    for (i = k + 1; i < size; i++) {
        A[0] = A[i];
        maxify(A, k + 1,0);
    }
}

void k_min2(int A[], int size, int k) 
{
    int i;
    int j;
    for (i = 0; i < k; i++) {
        for (j = 0; j < size - i - 1; j++)
            if (A[j] < A[j+1])
                swap(&A[j], &A[j+1]);
    }
}

void test2()
{
    int A[] = {10, 1, 2, 6, 10, 18, 9};
    k_min(A, 7, 3);
    int i;
    for (i = 0; i < 7; i++)
        printf("A[%d]=%d\n", i, A[i]);
}

void test1() 
{
    int A[] = {1, 2, 0, 8, 6, 10};
    heap_sort(A, 6);
}

void test3()
{
    int A[] = {10, 1, 2, 6, 10, 18, 9};
    k_min2(A, 7, 3);
    int i;
    for (i = 0; i < 3; i++) {
        printf("%d\n", A[7 - i - 1]);
    }
}

int main(int argc, const char *argv[]) 
{
    test1();
    test2();
    test3();
    return 0;
}
