#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int* arr, int len)
{
    for (int i = 0 ; i < len-1; ++i)
    {
        for (int j = 0; j < len-1-i; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main()
{
    srand(time(NULL));
    int arr[10];

    for (int i = 0; i < 10; ++i)
        arr[i] = rand() % 10 + 1;

    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);

    bubble_sort(arr, 10);
    
    printf("\n");

    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);

    return 0;
}