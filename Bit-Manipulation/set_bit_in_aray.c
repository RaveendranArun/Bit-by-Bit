#include <stdio.h>
#include <stdint.h>

void show(uint8_t* buf, uint8_t len)
{
    for (int iter = 0; iter < len; ++iter)
    {
        printf("0x%x ", buf[iter]);
    }

    printf("\n");
}

void set_bit_in_byte(uint8_t* buf, uint8_t len, uint8_t pos)
{
    uint8_t byte_index = pos / (sizeof(uint8_t) * 8);
    uint8_t bit_in_byte = pos % (sizeof(uint8_t) * 8);

    printf("%d %d\n", byte_index, bit_in_byte);
    buf[byte_index] |= (1 << bit_in_byte); 
}

int main()
{
    uint8_t buf[] = {0xAB, 0xFF, 0xBA, 0x11};

    show(buf, 4);

    set_bit_in_byte(buf, 4, 16);

    show(buf, 4);
    return 0;
}
