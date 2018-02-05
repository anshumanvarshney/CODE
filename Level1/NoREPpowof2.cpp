/*
Program to find whether a no is power of two
Given a positive integer, write a function to find if it is a power of two or not.

Examples:

Input : n = 4
Output : Yes
2^2 = 4

Input : n = 7
Output : No

Input : n = 32
Output : Yes
2^5 = 32
*/

#include<bits/stdc++.h>
using namespace std;


/*does not work for 10000000000000000 type value 
string check(int n)
{
	if(n==1) return "YES";
	if(n%2!=0) return "NO";
	int t=1,temp,i;
	temp=2;
	while(t<=n)
	{
		t=temp*t;
		if(t==n) return "YES";
	}
	return "NO";
}
*/

bool isPowerOfTwo(int n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
    if (n%2 != 0)
      return 0;
    n = n/2;
  }
  return 1;
}

//or return n&&(!(n&(n-1))) give directly answer

int main()
{
	int p,n;
	cin>>p;
	while(p--)
	{
		cin>>n;
		cout<<check(n)<<"\n";
	}
}