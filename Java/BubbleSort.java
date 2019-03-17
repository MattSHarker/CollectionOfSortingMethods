
// Matthew Harker
// Bubble Sort in Java

import java.util.Random;

public class BubbleSort
{
    public static final int SIZE = 8;
    public static final int MAX_RAND = 99;

    // an optimized version of Bubble Sort
    public static void bubbleSort(int arr[])
    {
        int size = arr.length;
        boolean swapped;

        for (int i = 0; i < size; i++)
        {
            swapped = false;

            for (int j = 0; j < size - i -1; j++)
            {
                if (arr[j] > arr[j+1])
                {
                    int temp = arr[j];  // because I can't just make a swap function >.<
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;

                    swapped = true;
                }
            }

            if (!swapped)   // if nothing was swapped then array is sorted
                break;
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

        System.out.println("Bubble Sort in Java");
        System.out.print("Original Array: ");
        printArray(arr);

        // sort array
        bubbleSort(arr);

        System.out.print("Sorted Array:   ");
        printArray(arr);
    }
}