
// Matthew Harker
// Heap Sort in C++

#include <iostream>
#include "sortUtilities.hpp"

using namespace std;

const int SIZE = 8;


// heapifies an array
void heapify(int* arr, int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

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

// standard insertion sort algorithm
void heapSort(int* arr, int size)
{
    // rearrange array into a heap
    for (int i = size/2 - 1; i >= 0; --i)
        heapify(arr, size, i);
    
    for (int i = size - 1; i >= 0; --i)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


int main()
{
    cout << "Heap Sort" << endl;

    int arr[SIZE];
    initArr(arr, SIZE);

    cout << "Original Array: ";
    printArr(arr, SIZE);

    heapSort(arr, SIZE);

    cout << "Sorted Array:   ";
    printArr(arr, SIZE);

    return 0;
}

