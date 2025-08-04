#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void* aligned_malloc(size_t size, size_t alignment)
{
    if ((alignment & (alignment - 1)) != 0)
    {
        return NULL; // alignment is not a power of two
    }

    uintptr_t raw = (uintptr_t)malloc(size + sizeof(void*) + alignment - 1);
    if (!raw)
        return NULL;

    // Align the pointer
    uintptr_t aligned = (raw + sizeof(void*) + alignment - 1) & ~(alignment -1); 
    // Store the original pointer just before the aligned pointer
    ((uintptr_t*)aligned)[-1] = raw;
    
    return (void* )aligned;
}

int main()
{
    size_t size = 100;
    size_t alignment = 8; // in bytes

    void* ptr = aligned_malloc(size, alignment);

    if (!ptr)
    {
        printf("Allocation failed\n");
        return 0;
    }

    if (((uintptr_t)ptr % alignment) == 0)
    {
        printf("Address is %zu bytes aligned\n", alignment);
    }
    else
    {
        printf("Not aligned");
    }

    return 0;
}