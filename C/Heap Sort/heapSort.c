
// Matthew Harker
// Heap Sort using C

#include <stdio.h>
#include "sortUtilities.h"

#define SIZE 8

// heapifies an array
void heapify(int* arr, int size, int index)
{
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (left < size && arr[largest] < arr[left])
        largest = left;
    
    if (right < size && arr[largest] < arr[right])
        largest = right;
    
    if (largest != index)
    {
        swap(&arr[index], &arr[largest]);
        heapify(arr, size, largest);
    }
}

// standard heapsort algorithm
void heapSort(int* arr, int size)
{
    // rearrange array into a heap
    for (int i = size/2 - 1; i >= 0; --i)
        heapify(arr, size, i);
    
    for (int i = size-1; i >= 0; --i)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


int main()
{
    printf("Heap Sort\n");

    int arr[SIZE];
    initArr(arr, SIZE);

    printf("Original array: ");
    printArr(arr, SIZE);

    heapSort(arr, SIZE);
    
    printf("Sorted array:   ");
    printArr(arr, SIZE);

    return 0;
}

