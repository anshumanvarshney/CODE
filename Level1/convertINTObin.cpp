/*
convert into binary number from 1 to number

Example:
Input
2
2
5

Output
1 10
1 10 11 100 101
*/

#include<bits/stdc++.h>
using namespace std;

int bin(int n)
{
	int a[10],i=0,j;
	while(n!=0)
	{
		a[i++]=n%2;
		n=n/2;
	}
	for(j=i-1;j>=0;j--)
		cout<<a[j];
	cout<<" ";
}

int main()
{
	int p,i;
	cin>>p;
	while(p--)
	{
		int n;
		cin>>n;
		for(i=1;i<=n;i++)
			bin(i);
		cout<<"\n";
	}
}