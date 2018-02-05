#include <iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	int a[10],n,i,j;
	cout<<"\nEnter no. of elements :";
    cin>>n;
	cout<<"\nEnter Elements :";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0,j=n-1;i<n/2;i++,j--)
	{
		cout<<a[j]<<" "<<a[i]<<" ";
	}
}