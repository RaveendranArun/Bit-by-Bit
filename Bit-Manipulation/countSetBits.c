#include <stdio.h>
#include <stdint.h>

uint32_t bit_width(uint32_t n)
{
    uint32_t width = 0;

    while (n)
    {
        width++;
        n >>= 1;
    }

    return width;
}

uint32_t countBits(uint32_t n)
{
    int count = 0;
    
    while (n)
    {
        uint32_t x = bit_width(n) - 1;
        count += x << (x - 1);
        n -= (1 << x);
        count += n + 1;
    }

    return count;
}

int main()
{
    int n = 7;
    printf("%d\n", countBits(n));

    return 0;
}