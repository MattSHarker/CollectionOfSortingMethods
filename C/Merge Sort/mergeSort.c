
// Matthew Harker
// Merge Sort using C

#include <stdio.h>
#include "sortUtilities.h"

#define SIZE 8

// merges two arrays
void merge(int* arr, int left, int mid, int right)
{
    int sizeL = mid - left + 1;
    int sizeR = right - mid;

    int arrL[sizeL];
    int arrR[sizeR];

    for (int i = 0; i < sizeL; ++i)
        arrL[i] = arr[left + 1];
    
    for (int i = 0; i < sizeR; ++i)
        arrR[i] = arr[mid + 1 + i];
    
    int l = 0;      // for left temp array
    int r = 0;      // for right temp array
    int m = left;   // for main array

    while (l < sizeL && r < sizeR)
    {
        if (arrL[l] < arrR[r])
            arr[m++] = arrL[l++];
        
        else
            arr[m++] = arrR[r++];
    }

    // if there are any elements left, copy them to the main array
    while (l < sizeL)
        arr[m++] = arrL[l++];

    while (r < sizeR)
        arr[m++] = arrR[r++];
}

// an optimized version of bubble sort
void mergeSort(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        // merge the two halves together
        merge(arr, left, mid, right);
    }
}


int main()
{
    printf("Merge Sort\n");
    
    int arr[SIZE];
    initArr(arr, SIZE);

    printf("Original array: ");
    printArr(arr, SIZE);

    mergeSort(arr, 0, SIZE-1);
    
    printf("Sorted array:   ");
    printArr(arr, SIZE);

    return 0;
}