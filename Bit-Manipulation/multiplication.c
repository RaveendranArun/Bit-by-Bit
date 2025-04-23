#include <stdio.h>
#include <stdbool.h>

int multiply(int a , int b)
{
    bool isNegative = false;
    int result = 0;

    if (a < 0)
    {
        a = -a;
        isNegative = !isNegative;
    }

    if (b < 0)
    {
        b = -b;
        isNegative = !isNegative;
    }

    while (b)
    {
        if (b & 1)
        {
            result += a;
        }
        a <<= 1;
        b >>= 1;
    }

    return isNegative ? -result : result;
}

int main()
{
    int a = 3;
    int b = 5;

    printf("result: %d\n", multiply(a, b));

    return 0;
}