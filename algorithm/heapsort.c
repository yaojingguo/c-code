#include <stdio.h>
#include <stdlib.h>

// heapsort is unstable. Consider the following tree:
//                  10
//                 /  \
//                9    9_
// 9 is before 9_.
// After 10 is swaped with 9_, the tree becomes:
//                  9_
//                 / \
//                9  10
// 9 is now after 9_.
void info(int array[], int len) {
	int i;
	printf("=======================\n");
	for (i = 0; i < len; i++)
		printf("array[%d] = %d\n", i, array[i]);
}

void swap(int * left, int * right) {
	int temp;
	temp = *left;
	*left = *right;
	*right = temp;
}

void adjust_heap(int index, int array[], int len) {
	int left = 2 * index;
	int right = left + 1;
	int target = (right < len && array[left] < array[right]) ? right : left;
	if (array[index] < array[target]) {
		swap(&array[index], &array[target]);
		if (target <= len / 2 - 1)
			adjust_heap(target, array, len);
	}
}

void create_heap(int array[], int len) {
	int i;
	for (i = len / 2 - 1; i >= 0; i--) 
		adjust_heap(i, array, len);
}

void sort(int array[], int len) {
	int index = 0;
	while (index < len - 1) {
		swap(&array[0], &array[len - index - 1]);
		adjust_heap(0, array, len - index - 1);
		index++;
	}
}

void heap_sort(int array[], int len, int sorted[]) {
	create_heap(array, len);
	info(array, 6);
	sort(array, len);
}

int main(int argc, const char *argv[]) {
	int array[] = {1, 10, 2, 8, 5, 4};
	int sorted[6];
	int i;

	heap_sort(array, 6, sorted);

	info(array, 6);
	return 0;
}
