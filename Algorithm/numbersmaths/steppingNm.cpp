/*
Stepping Numbers

A number is called stepping number if all adjacent digits have an absolute difference of 1, e.g. '321'
 is a Stepping Number while 421 is not. Given two integers n and m, find the count of all the stepping numbers 
 in range [n, m].

Examples:

Input : n = 0, m = 21
Output : 13
Stepping no's are 0 1 2 3 4 5 6 7 8 9 10 12 21

Input : n = 10, m = 15
Output : 2
Stepping no's are 10, 12
*/

#include<bits/stdc++.h>
using namespace std;
//my logic
int check(int a)
{
	int c=0;
	int n,d;
	
	if(a>=0 && a<=9) return 1;
	n=a;
	while(n>=10)
	{
		d=n%10;
		n=n/10;
		if(abs((n%10)-d)!=1)
			return 0;
	}
	return 1;
}
/*
int check(int a)
{
	int n;
	if(a>=0 && a<=9) return 1;
	n=a;
	int prev=-1,curr;
	while(n!=0)
	{
		curr=n%10;
		if(prev==-1)
			prev=curr;
		else
		{
			if(abs(prev-curr)!=1)
				return 0;
		}
		prev=curr;
		n=n/10;
	}
	return 1;
	
}*/

int main()
{
	int a,b,c,i,p;
	cin>>p;
	while(p--)
	{
		c=0;
		cin>>a>>b;
		for(i=a;i<=b;i++)
		{
			c+=check(i);
		}
		cout<<c<<"\n";
	}
}