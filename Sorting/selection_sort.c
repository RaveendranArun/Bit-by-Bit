#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int* arr, int len)
{
    for (int i = 0 ; i < len-1; ++i)
    {
        for (int j = i+1; j < len; ++j)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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

    selection_sort(arr, 10);
    
    printf("\n");

    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);

    return 0;
}