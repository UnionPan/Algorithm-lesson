/* C++ implementation of QuickSort */
#include<stdlib.h> 
#include<stdio.h> 
#include<iostream>

using namespace std;
  
// A utility function to swap two elements  
void swap(int* a, int* b){  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high){  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++){  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot){  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high){  
    if (low < high){  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
  
void threeWayPartition(int arr[], int n, 
                int lowVal, int highVal) 
{ 
    // Initialize ext available positions for 
    // smaller (than range) and greater lements 
    int start = 0, end = n-1; 
  
    // Traverse elements from left 
    for (int i=0; i<=end;) 
    { 
        // If current element is smaller than 
        // range, put it on next available smaller 
        // position. 
        if (arr[i] < lowVal) 
            swap(arr[i++], arr[start++]); 
  
        // If current element is greater than 
        // range, put it on next available greater 
        // position. 
        else if (arr[i] > highVal) 
            swap(arr[i], arr[end--]); 
  
        else
            i++; 
    } 
} 

/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
}  
  
// Driver Code 
int main()  
{  
    int arr[] = {10, 7, 8, 3, 4, 2, 9, 1, 5,5, 3,7, 10, 5, 6,};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    printf("Sorted array: \n");  
    printArray(arr, n); 
    return 0;
}  
  