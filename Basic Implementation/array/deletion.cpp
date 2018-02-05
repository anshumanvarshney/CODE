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
	cout<<"\nEnter the position to be deleted :";
	cin>>p;
	for(i=p;i<5;i++)
	{
		a[i]=a[i+1];
	}
	cout<<"\nArray after deletion :";
	for(i=0;i<4;i++)
	{
		cout<<a[i]<<" ";
	}
}