#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void pack_30bits_to_15bytes(uint32_t input[4], uint8_t output[15])
{
    output[0] = (input[0] >> 0) & 0xFF;
    output[1] = (input[0] >> 8) & 0xFF;
    output[2] = (input[0] >> 16) & 0xFF;
    output[3] = ((input[0] >> 24) & 0x3F | (input[1] & 0x03) << 6);
    
    output[4] = (input[1] >> 2) & 0xFF;
    output[5] = (input[1] >> 10) & 0xFF;
    output[6] = (input[1] >> 18) & 0xFF;
    output[7] = (input[1] >> 26) && 0x3F ;

    output[8] = (input[2]);
}

void unpack_15bytes_to_30bits(packed, unpacked)
{

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