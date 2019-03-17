
// Matthew Harker
// Quick Sort in Java

import java.util.Random;

public class QuickSort
{
    public static final int SIZE = 8;
    public static final int MAX_RAND = 99;

    // partitions an array based on the last element
    public static int partition(int arr[], int left, int right)
    {
        int pivot = arr[right];
        int small = left - 1;

        for (int i = left; i < right; i++)
        {
            if (arr[i] < pivot)
            {
                int swap = arr[++small];
                arr[small] = arr[i];
                arr[i] = swap;
            }
        }

        int swap = arr[small + 1];
        arr[small + 1] = arr[right];
        arr[right] = swap;

        return (small + 1);
    }

    // standard insertion sort algorithm
    public static void quickSort(int arr[], int left, int right)
    {
       if (left < right)
       {
           int part = partition(arr, left, right);

           quickSort(arr, left, part - 1);
           quickSort(arr, part, right);
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

        System.out.println("Quick Sort in Java");
        System.out.print("Original Array: ");
        printArray(arr);

        // sort array
        quickSort(arr, 0, arr.length - 1);

        System.out.print("Sorted Array:   ");
        printArray(arr);
    }
}

