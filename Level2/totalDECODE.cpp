/*
Total Decoding Messages

A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded.

Example :
Given encoded message "123",  it could be decoded as "ABC" (1 2 3) or "LC" (12 3) or "AW"(1 23).
So total ways are 3.

Input:
2
3
123
4
2563

Output:
3
2

My algo:
1+(check for consecutive two no  1<=n<=26)
for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{
		if((a[i]*10+j)<=26)
			c++;
	}
	return c+1;
}	
*/

#include<bits/stdc++.h>
using namespace std;

int decode(string a,int n)
{
	if(a[0]=='0') return 0;//no. like 014578
	int i;
	int dp[1000];
	dp[0]=1;//note here if 0 then 1
	dp[1]=1;
	for(i=2;i<=n;i++)
	{
		dp[i]=0;
		
		 // If the last digit is not 0, then last digit must add to
        // the number of words
		if(a[i-1]>'0')//seperate case i.e 1 2 3 
			dp[i]=dp[i-1];
		
		// If second last digit is smaller than 2 and last digit is
        // smaller than 7, then last two digits form a valid character
		if((a[i-2]<'2' && a[i-2]>'0') || (a[i-2]=='2' && a[i-1]<'7'))
			dp[i]+=dp[i-2];
	}
	return dp[n];
}

int main()
{
	int p;
	cin>>p;
	string a;
	while(p--)
	{
		int n;
		cin>>n;
		cin>>a;
		cout<<decode(a,a.length());
	}
}