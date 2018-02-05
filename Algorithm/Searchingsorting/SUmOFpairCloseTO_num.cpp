/*
Given a sorted array and a number x, find a pair in array whose sum is closest to x. in O(n)
Examples:
Input: arr[] = {10, 22, 28, 29, 30, 40}, x = 54
Output: 22 and 30

Input: arr[] = {1, 3, 4, 7, 10}, x = 15
Output: 4 and 10

Algo Mine:
check for a[0]+a[n-1]<x
then i++
else j--
*/
//O(n^2)
#include<bits/stdc++.h>
using namespace std;

//O(n^2)
int main()
{
	int a[]={1, 3, 4, 7, 10};
	int n=sizeof(a)/sizeof(n);
	int i,min,j,x,u,v;
	cin>>x;
	min=abs(a[0]+a[1]-x);
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(min> abs(a[i]+a[j]-x))
			{
				min=abs(a[i]+a[j]-x);
				u=a[i];
				v=a[j];
			}
		}
	}
	cout <<" The closest pair is " <<u<<" and "<<v;
	return 0;
}


//O(n) efficient than above

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={1, 3, 4, 7, 10};
	int n=sizeof(a)/sizeof(n);
	int x;
	cin>>x;

int rl, rr;  // To store indexes of result pair
 
    // Initialize left and right indexes and difference between
    // pair sum and x
    int l = 0, r = n-1, diff = INT_MAX;
 
    // While there are elements between l and r
    while (r > l)
    {
       // Check if this pair is closer than the closest pair so far
       if (diff > abs(a[l] + a[r] - x) )
       {
           rl = l;
           rr = r;
           diff = abs(a[l] + a[r] - x);
       }
 
       // If this pair has more sum, move to smaller values.
       if (a[l] + a[r] > x)
           r--;
       else // Move to larger values
           l++;
    }
 
    cout <<" The closest pair is " << a[rl] << " and " << a[rr];
	return 0;
}