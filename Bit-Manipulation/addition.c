#include <stdio.h>
#include <stdbool.h>


int addition(int a, int b)
{
    int sum = 0;

    while (b)
    {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    return a;
}

int main()
{
    printf("sum: %d\n", addition(2, 3));

    return 0;
}
