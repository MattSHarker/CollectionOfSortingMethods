#ifndef __SORT_UTILITIES__
#define __SORT_UTILITIES__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAND 99

// initializes an array with random values from 0 to MAX (inclusive)
void initArr(int* arr, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; ++i)
        arr[i] = rand() % (MAX_RAND + 1);
}


// prints an array
// takes into account single digit numbers for consistancy
void printArr(const int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < 10)
            printf(" %d  ", arr[i]);
        else
            printf("%d  ", arr[i]);
    }
    
    printf("\n");
}


// swaps two ints
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

#endif