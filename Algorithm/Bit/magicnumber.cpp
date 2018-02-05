/*
Find n’th Magic Number
A magic number is defined as a number which can be expressed as a power of 5 or sum of unique powers of 5. 
First few magic numbers are 5, 25, 30(5 + 25), 125, 130(125 + 5), ….

Write a function to find the n’th Magic number.

Example:

Input: n = 2
Output: 25

Input: n = 5
Output: 130 

If we notice carefully the magic numbers can be represented as
 001, 010, 011, 100, 101, 110 etc, where 001 is 0*pow(5,3) + 0*pow(5,2) + 1*pow(5,1). 
 So basically we need to add powers of 5 for each bit set in given integer n
 
 
 algo mine
 :
CONVERT given no to binary 
 then 
 use pow fun inside loop to get the answer
 
*/

#include<bits/stdc++.h>
using namespace std;
/*
int magic(int n)
{
	int c=0,i=1;
	while(n!=0)
	{
		c+=(n%2)*pow(5,i++);
		n=n/2;
	}
	return c;
}
int main()
{
	int p;
	cin>>p;
	while(p--)
	{	
		int n;
		cin>>n;
		cout<<magic(n)<<"\n";
	}
}
*/
//method 2
int magic(int n)
{
	int p=1,ans=0;
	while(n!=0)
	{
		p*=5;
		if(n%2!=0)
			ans+=p;
		n=n/2;
	}
	return ans;
}
int main()
{
	int p;
	cin>>p;
	while(p--)
	{	
		int n;
		cin>>n;
		cout<<magic(n)<<"\n";
	}
}
