/*
Find two prime numbers with given sum
Given an even number (greater than 2 ), print two prime numbers whose sum will be equal to given number.
 There may be several combinations possible. Print only first such pair.

An interesting point is, a solution always exist according to Goldbach’s conjecture.

Examples:

Input: n = 74
Output: 3 71

Input : n = 1024
Output: 3 1021

Input: n = 66
Output: 5 61

Input: n = 9990
Output: 17 9973
*/
#include<bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
	int i;
	if(n<1)return false;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	int i=2;
	while(i<n)
	{
		if(isprime(i)&&isprime(n-i))
		{
			cout<<"\nTwo numbrs are "<<i<<" "<<n-i;
			break;
		}
		else i++;
	}
}
