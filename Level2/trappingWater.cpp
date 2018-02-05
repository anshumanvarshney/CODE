/*
Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

Examples:

Input: arr[]   = {2, 0, 2}
Output: 2
Structure is like below
| |
|_|
We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 0, 2, 0, 4}
Output: 10
Structure is like below
     |
|    |
|  | |
|__|_| 
We can trap "3*2 units" of water between 3 an 2,
"1 unit" on top of bar 2 and "3 units" between 2 
and 4.  See below diagram also.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int	p;
	cin>>p;
	while(p--)
	{
		int n;
		cin>>n;
		int a[n],i;
		for(i=0;i<n;i++)
			cin>>a[i];
		int l[n],r[n];
		ln[0]=a[0];
		r[n-1]=a[n-1];
		for(i=1;i<n;i++)
			l[i]=max(l[i-1],a[i]);
		for(i=n-2;i>=0;i--)
			r[i]=max(r[i+1],a[i]);
		int sum=0;
		for(i=0;i<n;i++)
			sum+=min(l[i],r[i])-a[i];
		cout<<sum<<"\n";
	}
}