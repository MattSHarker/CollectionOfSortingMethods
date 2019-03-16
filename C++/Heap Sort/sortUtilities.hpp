
#ifndef __SORT_UTILITIES_H
#define __SORT_UTILITIES_H


#include <cstdlib>
#include <iostream>
using namespace std;

const int MAX_RAND = 99;

// swaps two ints
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// fills an array with random numbers from 0 to size (inclusive)
void initArr(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % (MAX_RAND + 1);
}

// prints an array
void printArr(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < 10)
            cout << " " << arr[i] << "  ";
        else
            cout << arr[i] << "  ";
    }

    cout << endl;
}

#endif