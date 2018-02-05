/*
Numbers with same first and last digit

Given an range of number's starting with integer L and ending at R, the task is to count the numbers
 which have same first and last digits.

Example:
Input:
2
7 68
5 40

Output:
9
8
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int p,m,n,i,c;
	cin>>p;
	while(p--)
	{
		c=0;
		cin>>m>>n;
		for(i=m;i<=n;i++)
		{
			if(i<10)
				c++;
			else
			{
				int d=0,a=i,t=0,b=i;
				while(a!=0)
				{
					d=a%10;
					if(a==b)
						t=d;
					a=a/10;
				}
				if(t==d)
					c++;
			}
		}
		cout<<c<<"\n";
	}
}