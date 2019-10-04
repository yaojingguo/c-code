#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;

    // 5 * 4 = 20 bytes
    arr = (int*)malloc(5 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "malloc failed");
        return EXIT_FAILURE;
    }
    free(arr);

    // 5 * 4 = 20 bytes
    arr = (int*)calloc(5, sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "malloc failed");
        return EXIT_FAILURE;
    }
    free(arr);

    return 0;
}
