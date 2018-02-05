#include<iostream>
using namespace std;

int main()
{
	int a[10],i,n,p;
	cout<<"\nEnter element :";
	for(i=0;i<5;i++)
	{
		cin>>a[i];
	}
	cout<<"\nArray is :";
	for(i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\nEnter the number to be inserted :";
	cin>>n;
	cout<<"\nEnter the position :";
	cin>>p;
	for(i=5;i>=p;i--)
	{
		a[i]=a[i-1];
	}
	a[p-1]=n;
	cout<<"\nArray after insertion :";
	for(i=0;i<6;i++)
	{
		cout<<a[i]<<" ";
	}
}