
// Matthew Harker
// Insertion Sort in Java

import java.util.Random;

public class InsertionSort
{
    public static final int SIZE = 8;
    public static final int MAX_RAND = 99;

    // standard insertion sort algorithm
    public static void insertionSort(int arr[])
    {
        int size = arr.length;

        for (int i = 0; i < size; i++)
        {
            int curVal = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > curVal)
                arr[j+1] = arr[j--];
            
                arr[j+1] = curVal;
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

        System.out.println("Insertion Sort in Java");
        System.out.print("Original Array: ");
        printArray(arr);

        // sort array
        insertionSort(arr);

        System.out.print("Sorted Array:   ");
        printArray(arr);
    }
}