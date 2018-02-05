/*
Write an efficient C program to find the sum of contiguous subarray within 
a one-dimensional array of numbers which has the largest sum.

-2,1,-3,4,-1,2,1,-5,4

4+-1+2+1=6

My algo 
find max then traverse backward and forward 
compare at each step in both the direction
eg. 4-3=1      	4-1=3
    1+1=2		3+2=5
	2-2=0 		5+1=6
	end here	6-5=1
	here max=2	1+4=5
				end here 
				here max=6
max sum 

Another algo
Kadane’s Algorithm:

Initialize:
    max_so_far = INT_MIN//or 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_ending_here < 0)
            max_ending_here = 0
  (c) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
return max_so_far

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={-2,1,-3,4,-1,2,1,-5,4};
	int n=sizeof(a)/sizeof(int);
	int sum = INT_MIN, curr = 0;
 
    for (int i = 0; i <n; i++)
    {
        curr = curr + a[i];
        if (sum < curr)
            sum = curr;
 
        if (curr < 0)
            curr = 0;
    }
    cout<<sum;
	return 0;
}