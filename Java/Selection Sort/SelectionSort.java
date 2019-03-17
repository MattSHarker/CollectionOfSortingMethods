
// Matthew Harker
// Selection Sort in Java

import java.util.Random;

public class SelectionSort
{
    public static final int SIZE = 8;
    public static final int MAX_RAND = 99;

    // standard insertion sort algorithm
    public static void selectionSort(int arr[], int left, int right)
    {
        int size = arr.length;

        for (int i = 0; i < size - 1; i++)
        {
            int min = i;

            // find min element in bounded subarray
            for (int j = i + 1; j < size; j++)
                if (arr[j]< arr[min])
                    min = j;
            
            // swap min element and first element of subarray
            int swap = arr[min];
            arr[min] = arr[i];
            arr[i] = swap;
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

        System.out.println("Selection Sort in Java");
        System.out.print("Original Array: ");
        printArray(arr);

        // sort array
        selectionSort(arr, 0, arr.length - 1);

        System.out.print("Sorted Array:   ");
        printArray(arr);
    }
}

