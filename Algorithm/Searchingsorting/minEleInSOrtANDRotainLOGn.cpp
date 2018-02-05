/*
Find the minimum element in a sorted and rotated array in logn time
A sorted array is rotated at some unknown point, find the minimum element in it.

Following solution assumes that all elements are distinct.

Examples

Input: {5, 6, 1, 2, 3, 4}
Output: 1

Input: {1, 2, 3, 4}
Output: 1

Input: {2, 1}
Output: 1

my method
if(a[0]<a[1]) a[0] si minimum
else traverse until you get a[i]>a[i+1] then a[i+1] is minimum 
eg 5 6 1 2 3 4 
6>1 so 1 is minimum

Method 2:

When you split the sorted, rotated array into two halves (arr[1],..,arr[mid]) and (arr[mid+1],..,arr[n]),
 one of them is always sorted and the other always has the min. We can directly use a modified binary search 
 to keep searching in the unsorted half

// index of first element
l = 0

// index of last element.
h = arr.length - 1

// always restrict the search to the unsorted 
// sub-array. The min is always there.
while (arr[l] > arr[h]) {
        // find mid.
        mid = (l + h)/2
        // decide which sub-array to continue with.
        if (arr[mid] > arr[h]) {
                l = mid + 1
        } else {
                h = mid
        }
}
// answer
return arr[l]




A simple solution is to traverse the complete array and find minimum. This solution requires Θ(n) time.
We can do it in O(Logn) using Binary Search. If we take a closer look at above examples,
 we can easily figure out following pattern:

Method 1:

You can do this in O(logN) time.

Use a modified binary search to find the point of rotation which is an index i such that
arr[i] > arr[i+1].

Example:

[6,7,8,9,1,2,3,4,5]
       ^
       i
The two sub-arrays 
(arr[1], arr[2], .., arr[i]) and
(arr[i+1], arr[i+2], ..., arr[n]) are sorted.

The answer is  min(arr[1], arr[i+1])
*/
#include<bits/stdc++.h>
using namespace std;


int findMin(int arr[], int l, int h)
{

// always restrict the search to the unsorted 
// sub-array. The min is always there.
	while (arr[l] > arr[h]) //means that array is rotated
	{
        // find mid.
       int mid = (l + h)/2;
        // decide which sub-array to continue with.
        if (arr[mid] > arr[h])
		{
                l = mid + 1;//aage waala part
        } 
		else 
		{
                h = mid;//peeche waala part
        }
	}
// answer
	return arr[l];//lower value of the sorted array is min value
}

int main()
{
	 int arr1[] =  {1, 2, 3, 4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("The minimum element is %d\n", findMin(arr1, 0, n1-1));
 
    int arr2[] =  {1, 2, 3, 4};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("The minimum element is %d\n", findMin(arr2, 0, n2-1));
 
    int arr3[] =  {1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    printf("The minimum element is %d\n", findMin(arr3, 0, n3-1));
 
    int arr4[] =  {1, 2};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    printf("The minimum element is %d\n", findMin(arr4, 0, n4-1));
 
    int arr5[] =  {2, 1};
    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    printf("The minimum element is %d\n", findMin(arr5, 0, n5-1));
 
    int arr6[] =  {5, 6, 7, 1, 2, 3, 4};
    int n6 = sizeof(arr6)/sizeof(arr6[0]);
    printf("The minimum element is %d\n", findMin(arr6, 0, n6-1));
 
    int arr7[] =  {1, 2, 3, 4, 5, 6, 7};
    int n7 = sizeof(arr7)/sizeof(arr7[0]);
    printf("The minimum element is %d\n", findMin(arr7, 0, n7-1));
 
    int arr8[] =  {2, 3, 4, 5, 6, 7, 8, 1};
    int n8 = sizeof(arr8)/sizeof(arr8[0]);
    printf("The minimum element is %d\n", findMin(arr8, 0, n8-1));
 
    int arr9[] =  {3, 4, 5, 1, 2};
    int n9 = sizeof(arr9)/sizeof(arr9[0]);
    printf("The minimum element is %d\n", findMin(arr9, 0, n9-1));
	return 0;
}


/*
Method 2

int findMin(int arr[], int low, int high)
{
    // This condition is needed to handle the case when array is not
    // rotated at all
    if (high < low)  return arr[0];
 
    // If there is only one element left
    if (high == low) return arr[low];
 
    // Find mid
    int mid = (low + high)/2;
 
    // Check if element (mid+1) is minimum element. Consider
    // the cases like {3, 4, 5, 1, 2}
    if (mid < high && arr[mid] > arr[mid+1])//the point of rotation
       return arr[mid+1];
 
    // Check if mid itself is minimum element
    if (mid > low && arr[mid] < arr[mid - 1])//is also the point of rotaion
       return arr[mid];
 
    // Decide whether we need to go to left half or right half
    if (arr[high] > arr[mid])
       return findMin(arr, low, mid-1);
    return findMin(arr, mid+1, high);
}
*/
