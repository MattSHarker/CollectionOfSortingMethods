
// Matthew Harker
// Bubble Sort using C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define MAX_RAND 99


// initializes an array with random values from 0 to MAX (inclusive)
void initArr(int* arr, int size)
{
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


// an optimized version of bubble sort
void bubbleSort(int* arr, int size)
{
    int swapped = 0;

    for (int i = 0; i < size - 1; ++i)
    {
        swapped = 0;

        for(int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}


int main()
{
    srand(time(NULL));

    int arr[SIZE];
    initArr(arr, SIZE);

    printf("Original array: ");
    printArr(arr, SIZE);

    bubbleSort(arr, SIZE);
    
    printf("Sorted array:   ");
    printArr(arr, SIZE);

    return 0;
}