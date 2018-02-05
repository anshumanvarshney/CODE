/*
Number Of Open Doors

Consider a long alley with a N number of doors on one side. All the doors are closed initially. 
You move to and fro in the alley changing the states of the doors as follows: you open a door that is 
already closed and you close a door that is already opened. You start at one end go on altering the state
 of the doors till you reach the other end and then you come back and start altering the states of the doors again.

In the first go, you alter the states of doors numbered 1, 2, 3, … , n.

In the second go, you alter the states of doors numbered 2, 4, 6 …

In the third go, you alter the states of doors numbered 3, 6, 9 …

You continue this till the Nth go in which you alter the state of the door numbered N.

You have to find the number of open doors at the end of the procedure.

Input
5
372
2
100
825625
63542

Output
19
1
10
908
252
*/

/*
we observ for n=9;

we get 1 0 0 1 0 0 0 0 1
i.e at position 1 4 9 we get one
so only perfect square we get 1 
*/

#include<bits/stdc++.h>
using namespace std;

/*
//correct method
long check(long n)
{
	if(n<2) return 0;
	if(n==2) return 1;
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
		if(a[i]==1)
			c++;
	}
	return c;
}
*/

long check(long n)
{
	long i=1,j,c=0;
	while(i<=sqrt(n))
	{
		if(i*i<=n)
			c++;
		i++;
	}
	return c;
	
	/*
	or
	return floor(sqrt(n));
	*/
}


int main()
{
	long p;
	cin>>p;
	while(p--)
	{
		long n;
		cin>>n;
		cout<<check(n)<<"\n";
	}
	return 0;
}