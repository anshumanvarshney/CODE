#include<iostream>
using namespace std;

int main()
{
	int a[3][3]={1,2,3,4,5,6,5,3,7};
	int b[3][3]={3,2,3,4,7,6,4,9,7};
	int c[3][3],i,j,k;
	cout<<"Matrix A is :\n";
	for(i=0;i<3;i++)
	{
		cout<<"[ ";
		for(j=0;j<3;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"]\n";
	}
	cout<<"\nMatrix B is :\n";
	for(i=0;i<3;i++)
	{
		cout<<"[ ";
		for(j=0;j<3;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<"]\n";
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=0;
			for(k=0;k<3;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}	
	}
	cout<<"\nMatrix A*B is :\n";
	for(i=0;i<3;i++)
	{
		cout<<"[ ";
		for(j=0;j<3;j++)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<"]\n";
	}
	
	
}