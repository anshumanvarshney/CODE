/*We can search an element in one pass of Binary Search. The idea is to search

Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
         key = 3
Output : Found at index 8

Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
         key = 30
Output : Not found

Input : arr[] = {30, 40, 50, 10, 20}
        key = 10   
Output : Found at index 3

Algorithm:
1) Find middle point mid = (l + h)/2
2) If key is present at middle point, return mid.
3) Else If arr[l..mid] is sorted
    a) If key to be searched lies in range from arr[l]
       to arr[mid], recur for arr[l..mid].
    b) Else recur for arr[mid+1..r]
4) Else (arr[mid+1..r] must be sorted)
    a) If key to be searched lies in range from arr[mid+1]
       to arr[r], recur for arr[mid+1..r].
    b) Else recur for arr[l..mid] 
Below is C++ implementation of above idea.*/

// Search an element in sorted and rotated array using
// single pass of Binary Search


//do without using recursion also
#include<bits/stdc++.h>
using namespace std;
 
// Returns index of key in arr[l..h] if key is present,
// otherwise returns -1
int search(int arr[], int l, int h, int key)
{
    if (l > h) return -1;//no need to use while because of recursion
 
    int mid = (l+h)/2;
    if (arr[mid] == key) return mid;
 
    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid])
    {
        /* As this subarray is sorted, we can quickly
           check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid])//or if (key >= arr[l] && key < arr[mid]) because we already check for mid
           return search(arr, l, mid-1, key);
 
        return search(arr, mid+1, h, key);
    }
 
    /* If arr[l..mid] is not sorted, then arr[mid... r]
       must be sorted*/
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid+1, h, key);
 
    return search(arr, l, mid-1, key);
}
 
// Driver program
int main()
{
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 9;//now trace
    int i = search(arr, 0, n-1, key);
    if (i != -1) cout << "Index: " << i << endl;
    else cout << "Key not found\n";
}
/*Run on IDE
Output:

Index: 7*/