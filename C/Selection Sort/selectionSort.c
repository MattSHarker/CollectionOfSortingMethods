
// Matthew Harker
// Selection Sort using C

#include <stdio.h>
#include "sortUtilities.h"

#define SIZE 8

// standard selection sort algorithm
void selectionSort(int* arr, int size)
{
    // move boundry of what is being search
    for (int i = 0; i < size - 1; ++i)
    {
        int min = i;

        // find the minimum element
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;
        
        // swap min element with first element of subarray
        swap(&arr[min], &arr[i]);
    }
}


int main()
{
    printf("Selection Sort in C\n");

    int arr[SIZE];
    initArr(arr, SIZE);

    printf("Original array: ");
    printArr(arr, SIZE);

    selectionSort(arr, SIZE);
    
    printf("Sorted array:   ");
    printArr(arr, SIZE);

    return 0;
}