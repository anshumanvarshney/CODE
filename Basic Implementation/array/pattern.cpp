/*
123452345
2345 2345
345   345
45     45
5       5
*/
#include<iostream>
using namespace std;

int main()
{
	int i,j,k,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			cout<<j<<" ";
		}
		if(i==1)
		{
			for(j=2;j<=n;j++)
			{
			cout<<j<<" ";
			}
		}
		else
		{	
		 for(k=j;k<=i*4;k++)
		 { 
			cout<<" ";
		 }
		 for(j=i;j<=n;j++)
		 {
			cout<<j<<" ";
	   	 }
		}
		cout<<"\n";
	}
}
or
int main()
{
	int n=5;
	int i,j,k,x=1;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=5;j++)
		{
			cout<<j;
		}
			if(i==1)
			{
				for(j=i+1;j<=5;j++)
					cout<<j;
			}
			else 
			{
				for(k=1;k<=x;k++)
					cout<<" ";
				for(j=i;j<=5;j++)
					cout<<j;
				x+=2;
			}
			cout<<"\n";		
	}
}