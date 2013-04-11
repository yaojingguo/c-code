#include <stdio.h>
int min(int buf[], int p) {
    int index;
    int i;
    index = p - 2;
    for (i = p-1; i <= p; i++)
        if (buf[i] < buf[index])
            index = i;
    return index;
}

void swap(int *a, int *b) {
    int temp;
    if (a == b)
        return;
    temp = *a;
    *a = *b;
    *b = temp;
}

void info_array(int A[], int size) {
    int i;
    printf("------------\n");
    for (i = 0; i < size; i++)
        printf("A[%d] = %d\n", i, A[i]);
    printf("------------\n");
}

// A 2-pass in bubble sort.
void bubble_2_pass(int A[], int size) {
    int i;
    int min_index;
    for (i = 2; i < 6; i++) {
        min_index = min(A, i);
        swap(&A[i-2], &A[min_index]);
    }
}

void test1() {
    int A[] = {1, 3, 1, 2, 4, 4, 8, 3, 4, 4};
    bubble_2_pass(A, 10);
    info_array(A, 10);
}

void test2() {
    int A[] = {10, 6, 4, 20, 8, 11};
    bubble_2_pass(A, 6);
    info_array(A, 6); 
}

int main(int argc, const char *argv[]) {
    test2();
    return 0;
}
