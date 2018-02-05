/*
Bleak Numbers
Given an integer, check whether it is Bleak or not.

A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x,
 i.e., x + countSetBits(x) is not equal to n for any non-negative number x.

Examples :

3 is not Bleak as it can be represented
as 2 + countSetBits(2).

4 is t Bleak as it cannot be represented 
as sum of a number x and countSetBits(x)
for any number x.

Input:
3
4
167
3

Output:
1
0
0
*/

#include<bits/stdc++.h>
using namespace std;

int count(int n)
{
	int c=0;
	while(n>0)
	{
		c+=n%2;
		n>>=1;
	}
	return c;
}

int main()
{
	int n,i,t,p;
	cin>>p;
	while(p--)
	{
		t=1;
		cin>>n;
		for(i=1;i<n;i++)
		{
			if(i + count(i)==n)
				t=0;
		}
		cout<<t<<"\n";
	}
}