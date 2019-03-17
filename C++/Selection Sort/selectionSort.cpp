
// Matthew Harker
// Selection Sort in C++

#include <iostream>
#include "sortUtilities.hpp"

using namespace std;

const int SIZE = 8;


// standard selection sort algorithm
void selectionSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int min = i;

        // find the minimum element
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;
        
        // swap the min element with the first element of the subarray
        swap(&arr[min], &arr[i]);
    }
}


int main()
{
    cout << "Selection Sort in C++" << endl;

    int arr[SIZE];
    initArr(arr, SIZE);

    cout << "Original Array: ";
    printArr(arr, SIZE);

    selectionSort(arr, SIZE);

    cout << "Sorted Array:   ";
    printArr(arr, SIZE);

    return 0;
}

