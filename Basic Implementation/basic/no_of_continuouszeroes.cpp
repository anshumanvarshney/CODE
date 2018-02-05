// concept for checking continuous 00 …. Or 1111s
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
	int i,n,*p,c=0;
	
	cout<<"Enter size :";
	cin>>n;
	p=new int[n];
	cout<<"\nEnter binary no :";
	for(i=0;i<n;i++)
	{
		cin>>*(p+i);
	}
	for(i=0;i<n;i++)
	{
		if(*(p+i)==0&& *(p+i+1)==0)      //or a[i]&&a[i+1]
		{
			c++;
		}
	}
	cout<<"\nNo of continuous zeroes :"<<c+1;
	delete [] p;
}
