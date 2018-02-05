/*
Max value

In a given array A[] find the maximum value of (A[i] – i) - (A[j] – j) where i is not equal to j. 
i and j vary from 0 to n-1 and N is size of input array A[].  Value of N is always greater than 1.
*/
/*/
Algorithm

1) Find maximum value of arr[i] – i in whole array.
2) Find minimum value of arr[i] – i in whole array.
3) Return difference of above two values.
*/

#include<bits/stdc++.h>
using namespace std;
 
// Returns maximum value of (arr[i]-i) - (arr[j]-j)
int findMaxDiff(int arr[], int n)
{
    if (n < 2)
    {
        cout << "Invalid ";
        return 0;
    }
 
    int min_val = INT_MAX, max_val = INT_MIN;
    for (int i=0; i<n; i++)
    {
        if ((a[i]-i) > max_val)
            max_val = a[i] - i;
        if ((a[i]-i) < min_val)
            min_val = a[i]-i;
    }
 
    return (max_val - min_val);
}
 
// Driver program
int main()
{
    int arr[] = {9, 15, 4, 12, 13};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findMaxDiff(arr, n);
    return 0;
}