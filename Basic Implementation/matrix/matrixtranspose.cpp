#include<iostream>
using namespace std;

int main()
{
	int a[3][3]={1,2,3,4,5,6,5,3,7};
	int b[3][3],i,j,k;
	cout<<"Matrix is :\n";
	for(i=0;i<3;i++)
	{
		cout<<"[ ";
		for(j=0;j<3;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"]\n";
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			b[j][i]=a[i][j];
		}
	}
	cout<<"\nMatrix (A)^t is :\n";
	for(i=0;i<3;i++)
	{
		cout<<"[ ";
		for(j=0;j<3;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<"]\n";
	}
	
	
}