/*
Replace every array element by multiplication of previous and next
Given an array of integers, update every element with multiplication of previous and next elements with following exceptions. 
a) First element is replaced by multiplication of first and second.
b) Last element is replaced by multiplication of last and second last.
Input: arr[] = {2, 3, 4, 5, 6}
Output: arr[] = {6, 8, 15, 24, 30}

// We get the above output using following
// arr[] = {2*3, 2*4, 3*5, 4*6, 5*6} 
int O(n) time and O(1) space
*/


#include<bits/stdc++.h>

using namespace std;

/* o(n) time and space
int main()
{
	int a[]={2, 3, 4, 5, 6};
	int *b;
	int n=sizeof(a)/sizeof(int);
	b=new int[n];
	int i;
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			b[i]=a[i]*a[i+1];
		}
		else if(i==n-1)
		{
			b[i]=a[i]*a[i-1];
		}
		else
		{
			b[i]=a[i-1]*a[i+1];
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
*/
//O(n) == time complexity O(1)==space
int main()
{
	int a[]={2, 3, 4, 5, 6};
	int n=sizeof(a)/sizeof(int);

	int i;
	int pre,curr;
	pre=a[0];
	a[0]=a[0]*a[1];
	for(i=1;i<n-1;i++)
	{
		curr=a[i];
		a[i]=pre*a[i+1];
		pre=curr;
	}
	a[n-1]=curr*a[n-1];
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}