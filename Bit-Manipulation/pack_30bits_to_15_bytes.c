/* 
 * An array of 4 integers, where each integer has only 30 useful 
 * bits (total = 120 bits = 15 bytes), pack those 30-bit values 
 * tightly into a 15-byte uint8_t buffer.
 */

#include <stdio.h>
#include <stdint.h>

void pack_30bits_to_15bytes(uint32_t input[4], uint8_t output[15])
{
    uint32_t bit_pos = 0;

    // Clear the buffer
    for (int i = 0; i < 15; i++) 
        output[i] = 0;

    for (int i = 0; i < 4; ++i)
    {
        uint32_t value = input[i] & 0x3FFFFFFF;
        for (uint8_t b = 0 ; b < 30; ++b)
        {
            uint32_t byte_index = bit_pos / 8;
            uint32_t bit_in_byte = bit_pos % 8;
            
            if (value & (1 << b))
            {
                output[byte_index] |= (1 << bit_in_byte);
            }
            bit_pos++;
        }
    }
}

void unpack_15bytes_to_30bits(uint8_t input[15], uint32_t output[4])
{
    uint32_t bit_pos = 0;
    for (uint32_t i = 0; i < 4; ++i)
    {
        int value = 0;
        for (uint32_t b = 0; b < 30; ++b)
        {
            uint32_t byte_index = bit_pos / 8;
            uint32_t bit_in_byte = bit_pos % 8;

            if (input[byte_index] & (1 << bit_in_byte))
            {
                value |= (1 << b);
            }
            bit_pos++;
        }

        output[i] = value;
    }
}

int main() 
{
    uint32_t input[4] = {0x3AAAAAAA, 0x2BBBBBBB, 0x1CCCCCCC, 0x0DDDDDDD};  // 30-bit values
    uint8_t packed[15];
    uint32_t unpacked[4];

    pack_30bits_to_15bytes(input, packed);
    unpack_15bytes_to_30bits(packed, unpacked);

    for (int i = 0; i < 4; i++) 
    {
        printf("Original: 0x%08X | Unpacked: 0x%08X\n", input[i] & 0x3FFFFFFF, unpacked[i]);
    }

    return 0;
}
