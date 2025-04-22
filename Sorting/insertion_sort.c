#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int* arr, int len)
{
    for (int i = 0 ; i < len; ++i)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j-1])
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;

            j--;
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

    insertion_sort(arr, 10);
    
    printf("\n");

    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);

    return 0;
}