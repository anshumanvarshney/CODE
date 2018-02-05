/*
Smallest subarray with sum greater than a given value
Given an array of integers and a number x, find the smallest subarray with sum greater than the given value.

Examples:
arr[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

arr[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

arr[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250}
    x = 280
Output: 4
Minimum length subarray is {100, 1, 0, 200} 

A simple solution is to use two nested loops. The outer loop picks a starting element, 
the inner loop considers all elements (on right side of current start) as ending element.
Whenever sum of elements between current start and end becomes more than the given number,
update the result if current length is smaller than the smallest length so far.
*/

#include<bits/stdc++.h>
using namespace std;
/*
int main()
{
	int a[]={1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
	int n,x,i,j;
	n=sizeof(a)/sizeof(int);
	int curr;
	cout<<"\nEnter the value of x :";
	cin>>x;
	int len=n+1;
	for(i=0;i<n;i++)
	{
		if(x<a[i])
		{
			len=1;
			break;
		}
		curr=a[i];
		for(j=i+1;j<n;j++)
		{
			curr+=a[j];
			if (curr > x && (j - i + 1) < len)//length of this subarray is smaller than curr subarray then update length
                 len = (j - i + 1);//current length
        }
     }
     cout<<len;

		
	return 0;
}
*/
//another way
int main()
{
	int a[]={1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
	int n,x,i,j;
	n=sizeof(a)/sizeof(int);
	cout<<"\nEnter the value of x :";
	cin>>x;
	int len=n+1;
	for(i=0;i<n;i++)
	{
		int t=a[i];
		if(x<t)
		{
			len=1;
			break;
		}
		for(j=i+1;j<n;j++)
		{
			t+=a[j];
			if (t>x)//length of this subarray is smaller than curr subarray then update length
                len=min(len,j-i+1);
        }
     }
	 cout<<len;
	return 0;
}