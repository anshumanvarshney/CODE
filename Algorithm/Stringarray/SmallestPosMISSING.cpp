/*
Find the smallest positive number missing from an unsorted array in O(n) time and O(1) space 
You are given an unsorted array with both positive and negative elements. You have to find the 
smallest positive number missing from the array in O(n) time using constant extra space.
 You can modify the original array.

Examples

 Input:  {2, 3, 7, 6, 8, -1, -10, 15}
 Output: 1

 Input:  { 2, 3, -7, 6, 8, 1, -10, 15 }
 Output: 4

 Input: {1, 1, 0, -1, -2}
 Output: 2 
*/
//my solution
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={1, 1, 0, -1, -2};
	int n=sizeof(a)/sizeof(int);
	int i,t=1;
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		if(a[i]==t)
		{
			i=0;
			t++;
		}
		if(i==n-1)
		{
			cout<<t;
			break;
		}
	}
}
/*
//in O(n)
			
#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(int A[],int n) 
{
	for (int i = 0; i < n; i++)
	{
        if (A[i] > 0 && A[i] <= n)
			{
                int pos = A[i] - 1;
                if (A[pos] != A[i])
				{
					swap(A[pos], A[i]);
                        i--;
                }
            }
    }
    for (int i = 0; i < n; i++)
	{
        if (A[i] != i + 1) return (i + 1);
    }
    return n + 1;
}

int main()
{
	int a[]={1, 1, 0, -1, -2};
	int n=sizeof(a)/sizeof(int);
	cout<<firstMissingPositive(a,n);
}			
*/