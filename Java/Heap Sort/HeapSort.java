
// Matthew Harker
// Heap Sort in Java

import java.util.Random;

public class HeapSort
{
    public static final int SIZE = 8;
    public static final int MAX_RAND = 99;

    // heapifies an array
    public static void heapify(int arr[], int size, int index)
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
            int swap = arr[index];
            arr[index] = arr[largest];
            arr[largest] = swap;

            heapify(arr, size, largest);
        }
    }

    // standard insertion sort algorithm
    public static void heapSort(int arr[])
    {
        int size = arr.length;

        for (int i = size/2 - 1; i >= 0; --i)
            heapify(arr, size, i);
        
        for (int i = size - 1; i >= 0; --i)
        {
            int swap = arr[0];
            arr[0] = arr[i];
            arr[i] = swap;

            heapify(arr, i, 0);
        }
    }

    // prints out an array
    // takes into consideration single digit numbers for consistency
    public static void printArray(int arr[])
    {
        int size = arr.length;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] < 10)
                System.out.print(" " + arr[i] + "  ");
            else
                System.out.print(arr[i] + "  ");
        }

        System.out.println();
    }

    // creates an array of size "size" and randomizes it
    public static void randomizeArr(int[] arr)
    {
        int size = arr.length;
        Random rand = new Random();

        for (int i = 0; i < size; i++)
            arr[i] = rand.nextInt(MAX_RAND + 1);
    }

    public static void main(String args[])
    {
        // create and randomize array
        int[] arr = new int[SIZE];
        randomizeArr(arr);

        System.out.println("Heap Sort in Java");
        System.out.print("Original Array: ");
        printArray(arr);

        // sort array
        heapSort(arr);

        System.out.print("Sorted Array:   ");
        printArray(arr);
    }
}