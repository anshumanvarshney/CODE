/*
Rearrange an array so that arr[i] becomes arr[arr[i]] with O(1) extra space
Given an array arr[] of size n where every element is in range from 0 to n-1.
 Rearrange the given array so that arr[i] becomes arr[arr[i]]. This should be done with O(1) extra space.

Examples:

Input: arr[]  = {3, 2, 0, 1}
Output: arr[] = {1, 0, 3, 2}

Input: arr[] = {4, 0, 2, 1, 3}
Output: arr[] = {3, 4, 2, 0, 1}

Input: arr[] = {0, 1, 2, 3}
Output: arr[] = {0, 1, 2, 3}
If the extra space condition is removed, the question becomes very easy. 
The main part of the question is to do it without extra space.
*/

void rearrange(int a[], int n)
{
    // First step: Increase all values by (arr[arr[i]]%n)*n
    for (int i=0; i < n; i++)
        a[i] += (a[a[i]]%n)*n;
 
    // Second Step: Divide all values by n
    for (int i=0; i<n; i++)
        a[i] /= n;
}