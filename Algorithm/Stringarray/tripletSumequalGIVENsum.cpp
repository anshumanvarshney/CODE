/*
Find a triplet that sum to a given value O(n^2)
Given an array and a value, find if there is a triplet in array whose sum is equal to the given value.
 If there is such a triplet present in array, then print the triplet and return true.
 Else return false. For example, if the given array is {12, 3, 4, 1, 6, 9} and given sum is 24,
 then there is a triplet (12, 3 and 9) present in array whose sum is 24.

Input:
2
6 13
1 4 45 6 10 8
5 10
1 2 4 3 6

Output:
1
1


*/
#include<bits/stdc++.h>
using namespace std;

int check(int a[],int n,int x)
{
	int i,j;
	sort(a,a+n);
	for(i=0;i<n-2;i++)
	{
		int j=i+1,k=n-1;
		while(j<k)
		{
			if(a[i]+a[j]+a[k]==x)
				return 1;
			else if(a[i]+a[j]+a[k]>x)
				k--;
			else if(a[i]+a[j]+a[k]<x)
				j++;
		}
	}
	return 0;
}

int main()
{
	int p,n,i,x,*a;
	cin>>p;
	while(p--)
	{
		cin>>n>>x;
		a=new int[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		cout<<check(a,n,x)<<"\n";
	}
	return 0;
}