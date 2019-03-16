
// Matthew Harker
// Bubble Sort using C

#include <stdio.h>
#include "sortUtilities.h"

#define SIZE 8

// an optimized version of bubble sort
void bubbleSort(int* arr, int size)
{
    int swapped = 0;    // if it doesn't swap anything the array is sorted

    for (int i = 0; i < size - 1; ++i)
    {
        swapped = 0;

        for(int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}


int main()
{
    printf("Bubble Sort\n");

    int arr[SIZE];
    initArr(arr, SIZE);

    printf("Original array: ");
    printArr(arr, SIZE);

    bubbleSort(arr, SIZE);
    
    printf("Sorted array:   ");
    printArr(arr, SIZE);

    return 0;
}