// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to return the first missing positive 
// number from the given unsorted array 
//This is an O(n) space algorithm
int firstMissingPosOn(int A[], int n) 
{ 
  
    // To mark the occurrence of elements 
    bool present[n+1]; 
    
    // Mark the occurrences 
    for (int i = 0; i < n; i++) { 
  
        // Only mark the required elements 
        // All non-positive elements and 
        // the elements > n + 1 will never 
        // be the answer 
        // For example, the array will be {1, 2, 3} 
        // in the worst case and the result 
        // will be 4 which is n + 1 
        if (A[i] > 0 && A[i] < n+1) 
            present[A[i]] = true; 
        else
        {
            present[A[i]] = false;
        }
        
    } 
  
    // Find the first element which didn't 
    // appear in the original array 
    for (int i = 1; i < n; i++) 
        if (!present[i]) 
            return i; 
  
    // If the original array was of the 
    // type {1, 2, 3} in its sorted form 
    return n + 1; 
} 

void swap(int* a, int* b) 
{ 
    int temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
/* Utility function that puts all  
non-positive (0 and negative) numbers on left  
side of arr[] and return count of such numbers */
int segregate(int arr[], int size) 
{ 
    int j = 0, i; 
    for (i = 0; i < size; i++) { 
        if (arr[i] <= 0) { 
            swap(&arr[i], &arr[j]); 
            j++; // increment count of non-positive integers 
        } 
    } 
  
    return j; 
} 
  
/* Find the smallest positive missing number  
in an array that contains all positive integers */
int findMissingPositive(int arr[], int size) 
{ 
    int i; 
  
    // Mark arr[i] as visited by making arr[arr[i] - 1] negative. 
    // Note that 1 is subtracted because index start 
    // from 0 and positive numbers start from 1 
    for (i = 0; i < size; i++) { 
        if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0) 
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]; 
    } 
  
    // Return the first index value at which is positive 
    for (i = 0; i < size; i++) 
        if (arr[i] > 0) 
            // 1 is added because indexes start from 0 
            return i + 1; 
  
    return size + 1; 
} 
  
/* Find the smallest positive missing  
number in an array that contains  
both positive and negative integers */
int findMissing(int arr[], int size) 
{ 
    // First separate positive and negative numbers 
    int shift = segregate(arr, size); 
  
    // Shift the array and call findMissingPositive for 
    // positive part 
    return findMissingPositive(arr + shift, size - shift); 
} 
  
// Driver code 
int main() 
{ 
  
    int A[] = { 1,2,3,4,5,6,7,8,9 }; 
    int size = sizeof(A) / sizeof(A[0]); 
    cout << firstMissingPosOn(A, size) << '\n'; 
    cout << findMissing(A, size);
} 