/*
Example:
Input
2
1004
121

Ouput
1554
121
*/

#include<bits/stdc++.h>
using namespace std;

int fn(int n)
{
	int r=0,r1=0,d;
	while(n!=0)
	{
		d=n%10;
		if(d==0)
			d=5;
		r=r*10+d;
		n=n/10;
	}
	while(r!=0)
	{
		d=r%10;
		r1=r1*10+d;
		r=r/10;
	}
	return r1;
}

int main()
{
	int a,p;
	cin>>p;
	while(p--)
	{
		cin>>a;
		cout<<fn(a)<<"\n";
	}
}