/* Given an array of distinct elements, rearrange the elements of array in zig-zag fashion in O(n) time. 
The converted array should be in
 form a < b > c < d > e < f.

 A Simple Solution is to first sort the array. After sorting, exclude the first element, swap the remaining elements in pairs. 
(i.e. keep arr[0] as it is, swap arr[1] and arr[2], swap arr[3] and arr[4], and so on). Time complexity is O(nlogn) 
since we need to sort the array first.

We can convert in O(n) time using an Efficient Approach. The idea is to use modified one pass of bubble sort. 

i.e if a[i] greater than a[i+1] then swap in first time 
	i++;
    if a[i] less than a[i+1] then swap in second time

Maintain a flag for representing which order(i.e. < or >) currently we need. If the current two elements are not in 
that order then swap those elements otherwise not.
Let us see the main logic using three consecutive elements A, B, C. Suppose we are processing B and C currently and
 the current relation is ‘<'. 
But we have B > C. Since current relation is ‘<' previous relation must be '>‘ i.e., A must be greater than B. So, 
the relation is A > B and B > C. We can deduce A > C. So if we swap B and C then the relation is A > C and C < B.
 Finally we get the desired order A C B */

// C++ program to sort an array in Zig-Zag form
#include <iostream>
using namespace std;
 
// Program for zig-zag conversion of array
void zigZag(int arr[], int n)
{
    // Flag true indicates relation "<" is expected,
    // else ">" is expected.  The first expected relation
    // is "<"
    bool flag = true;
 
    for (int i=0; i<=n-2; i++)
    {
        if (flag==true)  
        {
            if (arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
        }
        else // if (flag==false)
        {
            if (arr[i] < arr[i+1])
                swap(arr[i], arr[i+1]);
        }
        flag = !flag; /* flip flag */  //true to false and false to true
    }
}
 
// Driver program
int main()
{
    int  arr[] = {4, 3, 7, 8, 6, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
	
    zigZag(arr, n);
    for (int i=0; i<n; i++)
        cout << arr[i] << "  ";
    return 0;
}