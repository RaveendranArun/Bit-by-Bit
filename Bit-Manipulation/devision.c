#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

int division(int a, int b)
{
    if (b == 0)
        return INT_MAX;
    
    if (a == INT_MIN && b == -1)
        return INT_MAX;

    long long n = llabs((long long)a);
    long long d = llabs((long long)b);
    long long result = 0;

    while (n >= d)
    {
        int shift = 0;
        while (n >= d * (1 << (shift +1)))
        {
            shift++;
        }

        n -= d * (1 << shift);
        result += (1 << shift);
    }

    bool isNegative = (a < 0) ^ (b < 0);
    return isNegative ? -(int)result : (int)result;
}

int main()
{
    int n = 21;
    int d = 7;
    printf("Division: %d\n", division(n, d));
    return 0;
}