/*Pythagorean Triplet in an array
Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

Example:

Input: arr[] = {3, 1, 4, 6, 5}
Output: True
There is a Pythagorean triplet (3, 4, 5).

Input: arr[] = {10, 4, 6, 12, 5}
Output: False
There is no Pythagorean triplet.*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[] = {3, 1, 4, 6, 5};
	int n=sizeof(a)/sizeof(int);
	sort(a,a+n);
	int i,j,c=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			c=a[i]*a[i]+a[j]*a[j];
			if(c==a[j+1]*a[j+1])
			{
				cout<<"Yes";
				break;
			}
		}
	}
}

/*
or without sorting

// A C++ program that returns true if there is a Pythagorean
// Triplet in a given aray.
#include <iostream>
using namespace std;
 
// Returns true if there is Pythagorean triplet in ar[0..n-1]
bool isTriplet(int ar[], int n)
{
    for (int i=0; i<n; i++)
    {
       for (int j=i+1; j<n; j++)
       {
          for (int k=j+1; k<n; k++)
          {
            // Calculate square of array elements
            int x = ar[i]*ar[i], y = ar[j]*ar[j], z = ar[k]*ar[k];
 
            if (x == y + z || y == x + z || z == x + y) // because array is not sorted
                 return true;
          }
       }
    }
 
    // If we reach here, no triplet found
    return false;
}
 
/* Driver program to test above function */
int main()
{
    int ar[] = {3, 1, 4, 6, 5};
    int ar_size = sizeof(ar)/sizeof(ar[0]);
    isTriplet(ar, ar_size)? cout << "Yes": cout << "No";
    return 0;
}
*/