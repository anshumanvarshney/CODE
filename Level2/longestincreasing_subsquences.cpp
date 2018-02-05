/*
Dynamic Programming | Set 3 (Longest Increasing Subsequence)
We have discussed Overlapping Subproblems and Optimal Substructure properties in Set 1 and Set 2 respectively.

Let us discuss Longest Increasing Subsequence (LIS) problem as an example problem that can be solved using Dynamic Programming.
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence
such that all elements of the subsequence are sorted in increasing order. For example,
 the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.
longest-increasing-subsequence

More Examples:

Input  : arr[] = {3, 10, 2, 1, 20}
Output : Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

Input  : arr[] = {3, 2}
Output : Length of LIS = 1
The longest increasing subsequences are {3} and {2}

Input : arr[] = {50, 3, 10, 7, 40, 80}
Output : Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}

iterative algo 
 //algo mine without using dp 
int lis( int a[], int n )
{
	int *lis, i, j, max = 0,c;
	lis=new int[n];
	for(i=0;i<n;i++)
	{
		int x=a[i];
		c=1;
		for(j=i+1;j<n;j++)
		{
			if(x<a[j])
			{
				x=a[j];
				c++;
			}
		}
		lis[i]=c;
	}
	max=lis[0];
	for(i=0;i<n;i++)
	{
		if(max<lis[i])
			max=lis[i];
	}
	 delete []lis;
 
	return max;
} 

then max of b[i]

*/
/*
Geeks algo
maintain a lis[] array and initialise all element as 1 initially
now
for i=1.. n
 for j=0..n
 if(a[i]>a[j] && lis[i]<lis[j]+1)means we have to find longest sequence
	 then list[i]+=1; 
	 
	 {50, 3, 10, 7, 40, 80} implement this for better understanding
	 Output : Length of LIS = 4
		The longest increasing subsequence is {3, 7, 40, 80}
		
		
		BAsically we are making pairs from starting and if the back elements is suitable we increment 
		the lis[] of checked element
*/

#include<bits/stdc++.h>
using namespace std;
 
// lis() returns the length of the longest increasing subsequence in arr[] of size n 
int lis( int arr[], int n )
{
    int *lis, i, j, max = 0;
    lis = new int[n];
 
    // Initialize LIS values for all indexes 
    for (i = 0; i < n; i++ )
        lis[i] = 1;
 
    // Compute optimized LIS values in bottom up manner 
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ ) 
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
 
    // Pick maximum of all LIS values //or l[n];
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
 
    delete []lis;
 
    return max;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d\n", lis( arr, n ) );
    return 0;
}