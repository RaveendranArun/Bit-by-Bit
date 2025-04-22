#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int* arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while ((i <= high-1) && arr[i] <= pivot)
            i++;
        while ((j >= low + 1) && arr[j] > pivot)
            j--;
        
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }   
    }

    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}

void quick_sort(int* arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);

        quick_sort(arr, low, pIndex-1);
        quick_sort(arr, pIndex+1, high);
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

    quick_sort(arr, 0, 9);
    
    printf("\n");

    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);

    return 0;
}