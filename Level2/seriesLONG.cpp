/*
Crack the series
Given the series as follows 2 2 4 8 16 512....... Identify the nth term of the series. 
Answers can be very large use BigInt in Java.

Example:
Input:
2
4
7
Output:
8
256
*/

#include<bits/stdc++.h>
using namespace std;

int fid(int n)
{
	int flag=0,t;//for even
	if(n%2!=0)//if odd
	{
		flag=1;
		t=(n+1)/2;
	}
	else t=n/2;

	cout << fixed << setprecision(0);
	/*if the above statement not included then
	Input:
	11

	Its Correct output is:
	4294967296

	And Your Output is:
	4.29497e+09
	*/

	if(flag==0)
		cout<<pow(2,pow(3,t-1));
	if(flag==1)
		cout<<pow(2,pow(2,t-1));
}

int main()
{
	int n,p;
	cin>>p;
	while(p--)
	{
		cin>>n;
		fid(n);
	}
}