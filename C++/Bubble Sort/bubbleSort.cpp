
// Matthew Harker
// Bubble Sort in C++

#include <iostream>
#include "sortUtilities.hpp"

using namespace std;

const int SIZE = 8;


// an optimized version of bubble sort
void bubbleSort(int* arr, int size)
{
    bool swapped = false;   // if nothing swaps then list is sorted

    for (int i = 0; i < size; ++i)
    {
        swapped = false;

        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}


int main()
{
    cout << "Bubble Sort in C++" << endl;

    int arr[SIZE];
    initArr(arr, SIZE);

    cout << "Original Array: ";
    printArr(arr, SIZE);

    bubbleSort(arr, SIZE);

    cout << "Sorted Array:   ";
    printArr(arr, SIZE);

    return 0;
}

