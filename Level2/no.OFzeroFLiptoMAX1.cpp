/*
Flip Bits

Given an array arr[] consisting of 0’s and 1’s. A flip operation is one in which you turn 1 into 0 
and a 0 into 1.You have to do 
atmost one “Flip” operation on a subarray. Then finally display maximum number of 1 you can have in the array.

Example:
1
5
1 0 0 1 0 

Output:
4

Explanation:

We can perform a flip operation in the range [1,2]
After flip operation array is : 1 1 1 1 0

use kadane algorithm(for one time operation always use kadane algorithm)
*/

#include<bits/stdc++.h>
using namespace std;

int check(int a[],int n)
{
	int i,ones=0,max=0,temp=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
			ones++;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
			temp--;
		else temp++;
		if(temp<0)
			temp=0;
		if(temp>max)
			max=temp;
	}
	return ones+max;
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
		cout<<check(a,n)<<"\n";
	}
}