/*
Equilibrium index of an array
Equilibrium index of an array is an index such that the sum of elements at lower indexes is 
equal to the sum of elements at higher indexes
Input
2
4
1 2 0 3
4
1 1 1 1

Output
2
-1
*/

#include<bits/stdc++.h>
using namespace std;

int equi(int a[],int n)
{
	int i,rs=0,ls=0;
	for(i=0;i<n;i++)
		rs+=a[i];
	for(i=0;i<n;i++)
	{
		rs-=a[i];
		if(rs==ls)
			return i;
		ls+=a[i];
	}
}
int main()
{
	int a[]={1,2,0,3};
	int n=sizeof(a)/sizeof(int);
	cout<<equi(a,n)<<"\n";
}