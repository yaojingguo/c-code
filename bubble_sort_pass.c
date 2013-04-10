#include <stdio.h>
// A 2-pass in bubble sort.
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

int main(int argc, const char *argv[]) {
    int A[] = {1, 3, 1, 2, 4, 4, 8, 3, 4, 4};
    int min_index;
    int i;

    for (i = 2; i < 10; i++) {
        min_index = min(A, i);
        swap(&A[i-2], &A[min_index]);
    }

    printf("------------\n");
    for (i = 0; i < 10; i++)
        printf("| A[%d] = %d |\n", i, A[i]);
    printf("------------\n");

    return 0;
}
