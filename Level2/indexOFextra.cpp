/*
Find index of an extra element present in one sorted array
Given two sorted arrays. There is only 1 difference between the arrays. First array has one element extra added in between. 
Find the index of the extra element.

Examples:

Input : {2, 4, 6, 8, 9, 10, 12};
        {2, 4, 6, 8, 10, 12};
Output : 4
The first array has an extra element 9.
The extra element is present at index 4.

Input :  {3, 5, 7, 9, 11, 13}
         {3, 5, 7, 11, 13}
Output :  3

*/

// C++ program to find an extra element pre.sent
// in arr1[]
#include <iostream>
using namespace std;
 
// Returns index of extra element in arr1[].
// n is size of arr2[]. Size of arr1[] is
// n-1.
int findExtra(int arr1[], int arr2[], int n)
{
    int index = 0;  // Initialize result
 
    // left and right are end points denoting
    // the current range.
    int left = 0, right = n - 1;//n is length of small array
    while (left <= right)
    {
        int mid = (left+right) / 2;
 
        // If middle element is same of both
        // arrays, it means that extra element
        // is after mid so we update left to mid+1
        if (arr2[mid] == arr1[mid])
            left = mid + 1;
 
        // If middle element is different of the
        // arrays, it means that the index we are
        // searching for is either mid, or before
        // mid. Hence we update right to mid-1.
        else
        {
            index = mid;
            right = mid - 1;
        }
    }
 
    // when right is greater than left our
    // search is complete.
    return index;
}
 
// Driver code
int main()
{
    int arr1[]  =  {2, 4, 6, 8, 10, 12, 13};
    int arr2[] =  {2, 4, 6, 8, 10, 12};
    int n = sizeof(arr2) / sizeof(arr2[0]);
 
    // Solve is passed both arrays
    cout << findExtra(arr1, arr2, n);
    return 0;
}