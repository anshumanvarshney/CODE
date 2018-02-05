/*
Given a sorted array which is rotated 'N' times. Find the value of 'N'.
Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.

Input
2
5
5 1 2 3 4
5
1 2 3 4 5

Output
1
0

Algo mine
t>a[i] return i;
*/

#include<bits/stdc++.h>
using namespace std;

int rev(int a[],int n)
{
	int c=0,i,t=a[0];
	for(i=1;i<n;i++)
	{
		if(t>a[i])
		{
			c=i;
			break;
		}
		t=a[i];
	}
	return c;
}

int main()
{
	int p,n,*a,i;
	cin>>p;
	while(p--)
	{
		cin>>n;
		a=new int[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<rev(a,n)<<"\n";
	}
	return 0;
}