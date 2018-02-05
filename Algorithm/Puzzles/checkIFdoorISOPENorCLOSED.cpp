/*
Check if the door is open or closed

Given n doors and n persons. The doors are numbered from 1 to n and persons are given id’s numbered from 1 to n.
 Each door can have only two statuses ie open (1) or closed (0) . Initially all the doors have status closed.
 Find the final status of all the doors, when all the persons have changed the status of the doors of which they are
 authorized. i.e. if status open then change the status to closed and vice versa. 
 A person with id ‘i’ is authorized to change the status of door numbered ‘j’ if ‘j’ is a multiple of ‘i’.

Note: A person has to change the current status of all the doors for which he is authorized exactly once.

Example:

Input : 3
Output : 1 0 0 
Explanation : 
Initially status of rooms 0 0 0
person with id 2 changes room 2 to open ie (0 1 0)
person with id 1 changes room 1, 2, 3 status (1 0 1)
person with id 3 changes room 3 status ie (1 0 0)
*/

#include<bits/stdc++.h>
using namespace std;

void check(long n)
{
	long *a=new long[n];
	int i,j;
	memset(a,0,n*sizeof(a));
	for(i=1;i<=n;i++)
	{
		for(j=i-1;j<n;j+=i)
		{
			if(a[j]==0)
				a[j]=1;
			else if(a[j]==1) 
				a[j]=0;
		}
	}
	long c=0;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}



int main()
{
	long p;
	cin>>p;
	while(p--)
	{
		long n;
		cin>>n;
		check(n);
	}
	return 0;
}