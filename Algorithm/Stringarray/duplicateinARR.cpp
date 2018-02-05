/*
Find duplicates in O(n) time and O(1) extra space | Set 1
Given an array of n elements which contains elements from 0 to n-1, with any of these numbers appearing
 any number of times. Find these repeating numbers in O(n) and using only constant memory space.

For example, let n be 7 and array be {1, 2, 3, 1, 3, 6, 6}, the answer should be 1, 3 and 6.

Algo 
1- Traverse the given array from i= 0 to n-1 elements
     Go to index arr[i]%n  and increment its value by n.
	 so the element that are repeated will have a[element]>2*n 
3- Now traverse the array again and print all those 
   indexes i for which arr[i]/n is greater than 1.//because it return only floor value

This approach works because all elements are in range
from 0 to n-1 and arr[i]/n would be greater than 1
only if a value "i" has appeared more than once
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={1, 2, 3, 1, 3, 6, 6};
	int n=sizeof(a)/sizeof(int);
	int i;
	for(i=0;i<n;i++)
	{
		int index=a[i]%n;
		a[index]+=n;
	}
	//it convert the given array = {1,16,10,15,3,6,20}
	for(i=0;i<n;i++)
	{
		if(a[i]/n >1)//return integer value
			cout<<i<<" ";
			//return 1 3 6
	}
	return 0;
}