#include <stdio.h>
// without-sentinel
/*int findRightEnd(int array[], int begin, int end) {*/
/*  if (begin == end) {*/
/*    return begin;*/
/*  }*/
/*  int mid = (begin + end) / 2;*/
/*  printf("begin=%d, mid=%d, end=%d\n", begin, mid, end);*/

/*  if (array[mid] >= array[begin]) {*/
/*    int next = mid + 1;*/
/*    if (array[next] < array[mid])*/
/*      return mid;*/
/*    else*/
/*      return findRightEnd(array, mid + 1, end);*/
/*  } else {*/
/*    return findRightEnd(array, begin, mid - 1);*/
/*  }*/
/*}*/



// with-sentinel
int find2(int array[], int begin, int end, int sentinel) {
	if (begin == end)
		return begin;
	int mid = (begin + end) / 2;
	printf("begin=%d, mid=%d, end=%d\n", begin, mid, end);
	if (array[mid] >= sentinel) {
		int next = mid + 1;
		if (array[next] < sentinel)
			return mid;
		else
			return find2(array, mid + 1, end, sentinel);
	} else {
		return find2(array, begin, mid - 1, sentinel);
	}
}

int findRightEnd(int array[], int begin, int end) {
	return find2(array, begin, end, array[0]);
}
/*
 * ========================
 *       6 |
 *     5   |
 *   4     |
 * --------+--------
 *         |     3
 *         |   2
 *         | 1
 * ========================
 */
void test1() {
	int array[] = {4, 5, 6, 1, 2, 3}; int result = findRightEnd(array, 0, 5); printf("test1: %d\n", result);
}
void test2() {
	int array[] = {4, 5, 6, 1};       int result = findRightEnd(array, 0, 3); printf("test2: %d\n", result);
}
void test3() {
	int array[] = {4, 1, 2, 3};       int result = findRightEnd(array, 0, 3); printf("test3: %d\n", result);
}
void test4() {
	int array[] = {4, 4, 2, 3};       int result = findRightEnd(array, 0, 3); printf("test4: %d\n", result);
}
// with-sentinel can't handle this case.
void test_bad() {
	int array[] = {5, 8, 5, 5, 5};
	int result = findRightEnd(array, 0, 4);
	printf("test_bad: %d\n", result);
}
int main(int argc, const char *argv[]) {
	/*test1();*/
	/*test2();*/
	/*test3();*/
	/*test4();*/
	test_bad();
	return 0;
}
