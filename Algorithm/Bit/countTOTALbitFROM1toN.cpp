/*
Count total set bits in all numbers from 1 to n
Given a positive integer n, count the total number of set bits in binary representation of all numbers from 1 to n.

Examples:

Input: n = 3
Output:  4

Input: n = 6
Output: 9

Input: n = 7
Output: 12

Input: n = 8
Output: 13

My algo:
cin>>n
for n to 1
convert given no. into binary 
count no. of 1 
sum of count is required answer
*/

#include<bits/stdc++.h>
using namespace std;

//mine
int bin(int n)
{
	int c=0;
	while(n!=0)
	{
		c+=n%2;
		n=n/2;
	}
	return c;
}

/*
recursion
int bin(int n)
{
	if(n<=0)
		return 0;
	return ((n % 2 == 0)?0:1) + bin(n/2);
}
*/
/*
int bin(int n)
{
	int c=0;
	int a[10],i=0,j;
	while(n!=0)
	{
		a[i]=n%2;
		n/=2;
		i++;
	}
	for(j=i-1;j>=0;j--)
	{
		if(a[j]==1)
			c++;
	}
	return c;
}
*/



int main()
{
	int n,i,j=0,b[100],sum=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
	  sum+=bin(i);
	}	 
	cout<<sum;
}