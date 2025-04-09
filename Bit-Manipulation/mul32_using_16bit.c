#include <stdio.h>
#include <stdint.h>

uint32_t mul16(uint16_t x, uint16_t y)
{
    return (uint32_t)(x * y);
}

uint64_t mul(uint32_t x, uint32_t y)
{
    uint16_t x_low = x & 0xFFFF;
    uint16_t x_high = x >> 16;
    uint16_t y_low = y & 0xFFFF;
    uint16_t y_high = y >> 16;

    uint32_t p1 = mul16(x_high, y_high);
    uint32_t p2 = mul16(x_high, y_low);
    uint32_t p3 = mul16(y_high, x_low);
    uint32_t p4 = mul16(x_low, y_low);

    uint64_t res = 0;

    res += ((uint64_t)p1) << 32;
    res += ((uint64_t)(p2+p3)) << 16;
    res += (uint64_t)p4;

    return res;
}

int main()
{
    uint32_t a = 0x1234ABCD;
    uint32_t b = 0xABCD1234;

    uint64_t res = mul(a, b);
    printf("result: %lu\n", res);
    return 0;
}
