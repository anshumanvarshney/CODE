/*
Find the smallest positive integer value that cannot be represented as sum of any subset of a given array 
Given a sorted array (sorted in non-decreasing order) of positive numbers, find the smallest positive integer 
value that cannot be represented as sum of elements of any subset of given set. 
Expected time complexity is O(n).

Examples:

Input:  arr[] = {1, 3, 6, 10, 11, 15};
Output: 2

Input:  arr[] = {1, 1, 1, 1};
Output: 5

Input:  arr[] = {1, 1, 3, 4};
Output: 10

Input:  arr[] = {1, 2, 5, 10, 20, 40};
Output: 4

Input:  arr[] = {1, 2, 3, 4, 5, 6};
Output: 22
*/

#include<bits/stdc++.h>
using namespace std;
/*
int findSmallest(int arr[], int n)
{
   int res = 1; 
 
   // Traverse the array and increment 'res' if arr[i] is
   // smaller than or equal to 'res'.
   for (int i = 0; i < n && arr[i] <= res; i++)//a[i]<=res_curr
       res = res + arr[i];
 
   return res;
}
*/
//another way
int findSmallest(int a[], int n)
{
	int t=a[0];
	for(int i=1;i<n;i++)
	{
		if(t+1 >= a[i])
			t+=a[i];
		else break;
	}
	return t+1;
}

int main()
{
   int arr1[] = {1, 3, 4, 5};
   int n1 = sizeof(arr1)/sizeof(arr1[0]);
   cout << findSmallest(arr1, n1) << endl;
 
   int arr2[] = {1, 2, 6, 10, 11, 15};
   int n2 = sizeof(arr2)/sizeof(arr2[0]);
   cout << findSmallest(arr2, n2) << endl;
 
   int arr3[] = {1, 1, 1, 1};
   int n3 = sizeof(arr3)/sizeof(arr3[0]);
   cout << findSmallest(arr3, n3) << endl;
 
   int arr4[] = {1, 1, 3, 4};
   int n4 = sizeof(arr4)/sizeof(arr4[0]);
   cout << findSmallest(arr4, n4) << endl;
 
   return 0;
}