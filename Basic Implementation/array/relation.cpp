#include<iostream>
using namespace std;

void get(int a[][5],int);
void set(int a[][5],int);
void fn(int a[][5],int);
int main()
{
	int a[5][5],n;
	cout<<"Enter size of matrix :";
	cin>>n;
	get(a,n);
	set(a,n);
	fn(a,n);
	
}
int i,j;
void get(int a[][5],int n)
{
	cout<<"\nEnter element in the matrix :";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
}
void set(int a[][5],int n)
{
	cout<<"\nElement in the matrix :";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j];
		}
	}
}
void fn(int a[][5],int n)
{
	cout<<"\nRelationship : ";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	    {
			if(a[i][j]==1)
			{   
				cout<<i<<" knows "<<j<<"\n";
				if(i==n-1)
				{
					cout<<"\nid is : "<<j;
				}
			}
			
				
		}
	}
}