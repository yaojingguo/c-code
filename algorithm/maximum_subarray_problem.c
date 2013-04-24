#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) 
{
    return a >= b ? a : b;
}
// O(N^3)
int maxSum1(int *arr, int size) 
{
    int max_so_far;
    int sum;
    int l;
    int u;
    int i;
    max_so_far = 0;
    for (l = 0; l < size; l++) {
        for (u = l; u < size; u++) {
            sum = 0;
            for (i = l; i <= u; i++) {
                sum += arr[i];
            }
            max_so_far = max(max_so_far, sum);
        }
    }
    return max_so_far;
}
// O(N^2)
int maxSum2(int *arr, int size) 
{
    int max_so_far;
    int sum;
    int l;
    int u;
    int i;
    max_so_far = 0;
    for (l = 0; l < size; l++) {
        sum = 0;
        for (u = l; u < size; u++) {
            sum += arr[u];
            max_so_far = max(max_so_far, sum);
        }
    }
    return max_so_far;
}
// O(N^2)
int maxSum3(int *arr, int size) 
{
    int i;
    int *cumArray = (int *) malloc((size + 1) * sizeof(int));
    cumArray[0] = 0;

    for (i = 1; i <= size; i++) 
        cumArray[i] =  cumArray[i-1] + arr[i-1];

    int l;
    int u;
    int sum;
    int max_so_far;
    max_so_far = 0;
    for (l = 1; l < size; l++)
        for (u = l; u < size; u++) {
           sum = cumArray[u+1] - cumArray[l]; 
           max_so_far = max(max_so_far, sum);
        }

    free(cumArray);
    return max_so_far;
}
int maxSum4(int *arr, int l, int h) 
{
    if (l > h)
        return 0;
    if (l == h)
        return max(arr[l], 0);

    int m = (l + h) / 2;
    int i;
    int sumToRight = 0;
    for (i = h; i >= m+1; i--) 
        sumToRight = max(sumToRight + arr[i], 0);
    int sumToLeft = 0;
    for (i = l; i <= m; i++)
        sumToLeft = max(sumToLeft + arr[i], 0);
    int max_so_far = sumToLeft + sumToRight;
    max_so_far = max(max_so_far, maxSum4(arr, l, m));
    max_so_far = max(max_so_far, maxSum4(arr, m+1, h));
    return max_so_far;
}
// O(N)
int maxSum5(int *arr, int size)
{
    int i;
    int maxEndingHere;
    int max_so_far;

    maxEndingHere = 0;
    max_so_far = 0;
    for (i = 0; i < size; i++) {
        maxEndingHere = max(maxEndingHere + arr[i], 0);
        max_so_far = max(max_so_far, maxEndingHere); 
    }
    return max_so_far;
}

int main(int argc, const char *argv[]) 
{
    int data[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    printf("result: %d\n", maxSum1(data, 10));
    printf("result: %d\n", maxSum2(data, 10));
    printf("result: %d\n", maxSum3(data, 10));
    printf("result: %d\n", maxSum4(data, 0, 9));
    printf("result: %d\n", maxSum5(data, 10));
    return 0;
}
