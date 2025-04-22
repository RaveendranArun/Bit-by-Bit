#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* arr, int low, int mid, int high)
{
    int temp[low+high + 1];

    int left = low;
    int right = mid+1;
    int j = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[j++] = arr[left];
            left++;
        }
        else
        {
            temp[j++] = arr[right];
            right++;
        }
    }

    while (left <= mid)
        temp[j++] = arr[left++];
    while (right <= high)
        temp[j++] = arr[right++];

    for (int i = low; i <= high; ++i)
        arr[i] = temp[i - low];
}

void merge_sort(int* arr, int low, int high)
{
    if (low == high)
        return;                    // if low and high are equal, the array contains only one element
 
    int mid = (low + high) / 2;    // find the mid for the partition

    merge_sort(arr, low, mid);     // apply merge sort on the first half
    merge_sort(arr, mid+1, high);  // apply merge sort on the second half

    merge(arr, low, mid, high);    // Merge two sorted arrays
}

int main()
{
    srand(time(NULL));
    int arr[10];

    for (int i = 0; i < 10; ++i)
        arr[i] = rand() % 10 + 1;

    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);

    merge_sort(arr, 0, 9);
    
    printf("\n");

    for (int i = 0; i < 10; ++i)
        printf("%d ", arr[i]);

    return 0;
}