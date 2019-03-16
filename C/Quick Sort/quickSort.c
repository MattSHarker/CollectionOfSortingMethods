
// Matthew Harker
// Quick Sort using C

#include <stdio.h>
#include "sortUtilities.h"

#define SIZE 8

// partitions the array based on the last element in the subarray
int partition(int* arr, int left, int right)
{
    int pivot = arr[right];
    int smlInd = left - 1;   // index of the smallest element

    for (int i = left; i < right; ++i)
        if (arr[i] < pivot)
            swap(&arr[++smlInd], &arr[i]);
    
    swap(&arr[smlInd+1], &arr[right]);

    return (smlInd+ 1);
}

// standard quick sort algorithm
void quickSort(int* arr, int left, int right)
{
    if (left < right)
    {
        int partInd = partition(arr, left, right);

        quickSort(arr, left, partInd - 1);
        quickSort(arr, partInd, right);
    }
}


int main()
{
    printf("Quick Sort\n");

    int arr[SIZE];
    initArr(arr, SIZE);

    printf("Original array: ");
    printArr(arr, SIZE);

    quickSort(arr, 0, SIZE-1);
    
    printf("Sorted array:   ");
    printArr(arr, SIZE);

    return 0;
}

