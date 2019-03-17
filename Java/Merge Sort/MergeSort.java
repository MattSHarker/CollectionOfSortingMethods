
// Matthew Harker
// Merge Sort in Java

import java.util.Random;

public class MergeSort
{
    public static final int SIZE = 8;
    public static final int MAX_RAND = 99;

    // merges two connected subarrays into one sorted subarray
    public static void merge(int arr[], int left, int mid, int right)
    {
        int sizeL = mid - left + 1;
        int sizeR = right - mid;

        int[] arrL = new int[sizeL];
        int[] arrR = new int[sizeR];

        // copy the two halves of the main array into two temp arrays
        for (int i = 0; i < sizeL; i++)
            arrL[i] = arr[left + i];
        
        for (int i = 0; i < sizeR; i++)
            arrR[i] = arr[mid + 1 + i];
        
        int l = 0;
        int r = 0;
        int m = left;

        // merge the two arrays such that the new order is sorted
        while (l < sizeL && r < sizeR)
        {
            if (arrL[l] < arrR[r])
                arr[m++] = arrL[l++];
            
            else
                arr[m++] = arrR[r++];
        }

        // if there are any remaining elements add them to the array
        while (l < sizeL)
            arr[m++] = arrL[l++];
        
        while (r < sizeR)
            arr[m++] = arrR[r++];

    }

    // standard insertion sort algorithm
    public static void mergeSort(int arr[], int left, int right)
    {
        if (left < right)
        {
            int mid = (left + right) / 2;

            // recursively sort the two halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            // merge the two halves together
            merge(arr, left, mid, right);
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

        System.out.println("Merge Sort in Java");
        System.out.print("Original Array: ");
        printArray(arr);

        // sort array
        mergeSort(arr, 0, arr.length - 1);

        System.out.print("Sorted Array:   ");
        printArray(arr);
    }
}

