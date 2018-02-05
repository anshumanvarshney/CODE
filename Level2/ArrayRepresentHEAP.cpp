/*
How to check if a given array represents a Binary Heap?
Given an array, how to check if the given array represents a Binary Max-Heap.

Examples:

Input:  arr[] = {90, 15, 10, 7, 12, 2} 
Output: True
The given array represents below tree
       90
     /    \
   15      10
  /  \     /
 7    12  2 
The tree follows max-heap property as every
node is greater than all of its descendants.

Input:  arr[] = {9, 15, 10, 7, 12, 11} 
Output: False
The given array represents below tree
       9
     /    \
   15      10
  /  \     /
 7    12  11
The tree doesn't follows max-heap property 9 is 
smaller than 15 and 10, and 10 is smaller than 11. 
*/

/*
Algo:
using restoredown or below algo similar to restore down
*/
#include<bits/stdc++.h>
using namespace std;

bool isHeap(int arr[],  int n)
{
	int left,right;
    for (int i=0; i<=(n-2)/2; i++)//condition can also be valid if n/2
    {
        left=2*i+1;
		right=2*i+2;
		if(((left<n)&&a[left]>a[i])||((right<n)&&a[right]>a[i]))
			return false
    }
    return true;
}
 
// Driver program
int main()
{
    int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
    int n = sizeof(arr) / sizeof(int);
 
    isHeap(arr, n)? printf("Yes"): printf("No");
 
    return 0;
}