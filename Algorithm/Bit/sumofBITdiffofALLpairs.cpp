/*
Sum of bit differences among all pairs
Given an integer array of n integers, find sum of bit differences in all pairs that can be formed from array elements.
 Bit difference of a pair (x, y) is count of different bits at same positions in binary representations of x and y. 
For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 
( first and last bits differ in two numbers).

Examples:

Input: arr[] = {1, 2}
Output: 4
All pairs in array are (1, 1), (1, 2)
                       (2, 1), (2, 2)
Sum of bit differences = 0 + 2 +
                         2 + 0
                      = 4

Input:  arr[] = {1, 3, 5}
Output: 8
All pairs in array are (1, 1), (1, 3), (1, 5)
                       (3, 1), (3, 3) (3, 5),
                       (5, 1), (5, 3), (5, 5)
Sum of bit differences =  0 + 1 + 1 +
                          1 + 0 + 2 +
                          1 + 2 + 0 
                       = 8

					   
My algo:
see in an array like {1,2} the pairs become 1,1 1,2 2,1 2,2
 so 1,1 and 2,2 ruled out and we left only 1,2 and 2,1
 in which the diff is equal 
so run two loop so we get pair 1,2 find out the bit diff and multiply by two we get answer
*/
//my algo
#include <bits/stdc++.h>
using namespace std;

int count(int n)
{
	int c=0;
	while(n!=0)
	{
		c+=n%2;
		n=n/2;
	}
	return c;
}
int xorr(int a,int b)
{
	return ((a|b)&(~a|~b));
} 
int sumBitDifferences(int a[], int n)
{
	int c=0,i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			//int t=a[i]^a[j];
			int t=xorr(a[i],a[j]);
			c+=count(t);
		}
	}
 return c*2;
}
 
 // Driver prorgram
int main()
{
    int arr[] = {1, 3, 5};
    int n = sizeof(arr) / sizeof(int) ;	
	cout<<sumBitDifferences(arr, n);
   // cout << sumBitDifferences(arr, n) << endl;
    return 0;
}


/*
Algo 1:
A Simple Solution is to run two loops to consider all pairs one by one. For every pair,
 count bit differences. Finally return sum of counts. Time complexity of this solution is O(n2).

 Algo 2:
An Efficient Solution can solve this problem in O(n) time using the fact that all numbers are 
represented using 32 bits (or some fixed number of bits). The idea is to count differences at 
individual bit positions. We traverse from 0 to 31 and count numbers with i’th bit set.
 Let this count be ‘count’. There would be “n-count” numbers with i’th bit not set. 
 So count of differences at i’th bit would be “count * (n-count) * 2”.
*/
//Below is C++ implementation of above idea.

// C++ program to compute sum of pairwise bit differences
#include <bits/stdc++.h>
using namespace std;
/* 
int sumBitDifferences(int arr[], int n)
{
    int ans = 0;  // Initialize result
 
    // traverse over all bits
    for (int i = 0; i < 32; i++)
    {
        // count number of elements with i'th bit set
        int count = 0;
        for (int j = 0; j < n; j++)
		{
            if ( (arr[j] & (1 << i)) )
                count++;
		}
        // Add "count * (n - count) * 2" to the answer//*2 for symmetric ie. 1,3  3,1
        ans += (count * (n - count) * 2);
		//cout<<(count * (n - count) * 2)<<" ";
    }
 
    return ans;
}
 */
 


