/*
Problem: There is a colony of 8 cells arranged in a straight line where each day every cell competes with its 
adjacent cells(neighbour). Each day, for each cell, if its neighbours are both active or both inactive, 
the cell becomes inactive the next day, otherwise it becomes active the next day. 
Assumptions:
The two cells on the ends have single adjacent cell, so the other adjacent cell can be assumsed to be always inactive.
Even after updating the cell state. consider its previous state for updating the state of other cells.
 Update the cell information of all cells simultaneously.
Write a function cellCompete which takes takes one 8 element array of integers cells representing the current 
state of 8 cells and one integer days representing te number of days to simulate.
An integer value of 1 represents an active cell and value of 0 represents an inactive cell.

TEST CASES 1:

INPUT:
[1,0,0,0,0,1,0,0],1

EXPECTED RETURN VALUE:
[0,1,0,0,1,0,1,0]

TESTCASE 2:

INPUT:
[1,1,1,0,1,1,1,1,],2

EXPECTED RETURN VALUE:
[0,0,0,0,0,1,1,0]

*/

#include<bits/stdc++.h>
using namespace std;

int fn(int a[],int n,int d)
{
	int *b=new int[n+2];
	int *c=new int[n];
	b[-1]=b[8]=0;
	int i,j,k,l;
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	for(i=0;i<d;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[j-1]==b[j+1])
				c[j]=0;
			else c[j]=1;
		}
		for(l=0;l<n;l++)
			b[l]=c[l];
	}
	for(k=0;k<n;k++)
	{
		cout<<c[k]<<" ";
	}
	
}
int main()
{
	int a[]={1,1,1,0,1,1,1,1};
	int d=2;
	int n=sizeof(a)/sizeof(int);
	fn(a,n,d);
	
}