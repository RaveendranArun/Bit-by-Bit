#include <stdio.h>
#include <stdint.h>

uint16_t mul8(uint8_t x, uint8_t y)
{
    return (uint16_t)(x * y);
}

uint32_t mul(uint16_t x, uint16_t y)
{
    uint8_t x_low = x & 0xFF;
    uint8_t x_high = x >> 8;
    uint8_t y_low = y & 0xFF;
    uint8_t y_high = y >> 8;

    uint16_t p1 = mul8(x_high, y_high);
    uint16_t p2 = mul8(x_high, y_low);
    uint16_t p3 = mul8(y_high, x_low);
    uint16_t p4 = mul8(x_low, y_low);

    uint32_t res = 0;

    res += ((uint32_t)p1) << 16;
    res += ((uint32_t)(p2+p3)) << 8;
    res += (uint32_t)p4;

    return res;
}

int main()
{
    uint16_t a = 0x1234;
    uint16_t b = 0xABCD;

    uint32_t res = mul(a, b);
    printf("result: %u\n", res);
    return 0;
}
