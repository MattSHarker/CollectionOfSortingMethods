
// Matthew Harker
// Insertion Sort using C

#include <stdio.h>
#include "sortUtilities.h"

#define SIZE 8

// standard insertion sort algorithm
void insertionSort(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        int curVal = arr[i];
        int j = i-1;

        while (j >= 0 && arr[j] > curVal)
            arr[j+1] = arr[j--];
        
        arr[j+1] = curVal;
    }
}


int main()
{
    printf("Insertion Sort in C\n");

    int arr[SIZE];
    initArr(arr, SIZE);

    printf("Original array: ");
    printArr(arr, SIZE);

    insertionSort(arr, SIZE);
    
    printf("Sorted array:   ");
    printArr(arr, SIZE);

    return 0;
}