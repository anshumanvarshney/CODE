/*
Given two unsorted arrays A[] of size n and B[] of size m of distinct elements, the task is 
to find all pairs from both arrays whose sum is equal to x.

Examples:

Input :  A[] = {-1, -2, 4, -6, 5, 7}
         B[] = {6, 3, 4, 0}  
         x = 8
Output : 4 4, 5 3

Input : A[] = {1, 2, 4, 5, 7} 
        B[] = {5, 6, 3, 4, 8}  
        x = 9
Output : 1 8, 4 5, 5 4

Example:
Input:
2
5 5 9
1 2 4 5 7
5 6 3 4 8
2 2 3
0 2
1 3
Output:
1 8, 4 5, 5 4
0 3, 2 1

or using hashing
*/

#include<bits/stdc++.h>
using namespace std;

void check(int a[],int b[],int n,int m,int x)
{
	int i,j;
	sort(a,a+n);
	sort(b,b+m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i]+b[j]==x)
			{
				if(c>0) cout<<", ";
				c++;
				cout<<a[i]<<" "<<b[j];
			}
			
		}
	}
	if(c==0) cout<<"-1";
 }

int main()
{
	int p,n,m,*a,*b,x,i;
	cin>>p;
	while(p--)
	{
		cin>>n>>m>>x;
		a=new int[n];
		b=new int[m];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<m;i++)
			cin>>b[i];
		check(a,b,n,m,x);
	}
	
}