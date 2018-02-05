/*
Partition a set into two subsets such that the difference of subset sums is minimum
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between 
their sums is minimum.

If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements
 and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example:

Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11	
*/
//my algo
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={3, 1, 4, 2, 2, 1},i,sum=0;
	int n=sizeof(a)/sizeof(n);
	sort(a,a+n);
	int t=a[n-1];
	for(i=0;i<n-1;i++)
	{
		sum+=a[i];
	}
	int min=9999;
	i=0;
	while(i<n)
	{
		int y=a[i];
		if(abs(sum-t)<min)
		{
			min=sum-t;
		}
		sum-=y;
		t+=y;
		i++;
	}
	cout<<min;
	return 0;
}

