#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int divide(int a, int b);
int mod(int a, int b);

int main()
{
    // divide
    assert(divide(0, 5) == 0);

    assert(divide(10, 5) == 2);
    assert(divide(11, 5) == 2);

    assert(divide(-10, -5) == 2);
    assert(divide(-11, -5) == 2);

    assert(divide(5, -3) == -2);
    assert(divide(-5, 3) == -2);

    // mod
    assert(mod(5, 3) == 2);
    assert(mod(5, -3) == -1);
    assert(mod(-5, 3) == 1);
    assert(mod(-5, -3) == -2);
}

int mod(int a, int b) 
{
    int q = divide(a, b);
    printf("q: %d\n", q);
    return a - b * q;
}

int divide(int a, int b)
{
    if (a == 0 || b == 0) return a / b;
    if (a > 0 && b > 0) return a / b;
    if (a < 0 && b < 0) return a / b;
    int quotient = a / b;
    if (abs(quotient * b) < abs(a))
        quotient--;
    return quotient;
}
