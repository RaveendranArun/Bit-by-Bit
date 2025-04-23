#include <stdio.h>
#include <stdbool.h>


int substraction(int a, int b)
{
    int diff = 0;

    while (b)
    {
        int borrow = ~a & b;
        a = a ^ b;
        b = borrow << 1;
    }

    return a;
}

int main()
{
    printf("sum: %d\n", substraction(1, 2));

    return 0;
}
