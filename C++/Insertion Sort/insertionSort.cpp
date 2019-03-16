
// Matthew Harker
// Insertion Sort in C++

#include <iostream>
#include "sortUtilities.hpp"

using namespace std;

const int SIZE = 8;


// standard insertion sort algorithm
void insertionSort(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int curVal = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > curVal)
            arr[j+1] = arr[j--];
        
        arr[j+1] = curVal;
    }
}


int main()
{
    cout << "Bubble Sort" << endl;

    int arr[SIZE];
    initArr(arr, SIZE);

    cout << "Original Array: ";
    printArr(arr, SIZE);

    insertionSort(arr, SIZE);

    cout << "Sorted Array:   ";
    printArr(arr, SIZE);

    return 0;
}

