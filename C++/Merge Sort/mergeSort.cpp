
// Matthew Harker
// Merge Sort in C++

#include <iostream>
#include "sortUtilities.hpp"

using namespace std;

const int SIZE = 8;

// merges two arrays
void merge(int* arr, int left, int mid, int right)
{
    int sizeL = mid - left + 1;
    int sizeR = right - mid;

    int arrL[sizeL];
    int arrR[sizeR];

    for (int i = 0; i < sizeL; ++i)
        arrL[i] = arr[left + i];
    
    for (int i = 0; i < sizeR; ++i)
        arrR[i] = arr[mid + 1 + i];
    
    int l = 0;
    int r = 0;
    int m = left;

    while (l < sizeL && r < sizeR)
    {
        if (arrL[l] < arrR[r])
            arr[m++] = arrL[l++];
        
        else
            arr[m++] = arrR[r++];
    }

    while (l < sizeL)
        arr[m++] = arrL[l++];
    
    while (r < sizeR)
        arr[m++] = arrR[r++];
}

// standard insertion sort algorithm
void mergeSort(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // merge the two halves together
        merge(arr, left, mid, right);
    }
}


int main()
{
    cout << "Merge Sort" << endl;

    int arr[SIZE];
    initArr(arr, SIZE);

    cout << "Original Array: ";
    printArr(arr, SIZE);

    mergeSort(arr, 0, SIZE - 1);

    cout << "Sorted Array:   ";
    printArr(arr, SIZE);

    return 0;
}

