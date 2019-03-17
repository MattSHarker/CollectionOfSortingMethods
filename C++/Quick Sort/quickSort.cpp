
// Matthew Harker
// Quick Sort in C++

#include <iostream>
#include "sortUtilities.hpp"

using namespace std;

const int SIZE = 8;

// partitions an array based on the last element
int partition(int* arr, int left, int right)
{
    int pivot = arr[right];
    int small = left - 1;

    for (int i = left; i < right; ++i)
        if (arr[i] < pivot)
            swap(&arr[++small], &arr[i]);
    
    swap(&arr[small + 1], &arr[right]);

    return (small + 1);

}

// standard quick sort algorithm
void quickSort(int* arr, int left, int right)
{
    if (left < right)
    {
        int part = partition(arr, left, right);

        quickSort(arr, left, part - 1);
        quickSort(arr, part, right);
    }
}


int main()
{
    cout << "Quick Sort in C++" << endl;

    int arr[SIZE];
    initArr(arr, SIZE);

    cout << "Original Array: ";
    printArr(arr, SIZE);

    quickSort(arr, 0, SIZE - 1);

    cout << "Sorted Array:   ";
    printArr(arr, SIZE);

    return 0;
}

