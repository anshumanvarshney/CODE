#include <iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	int a[10],n,i,k,c=0;
	cout<<"\nEnter no. of elements :";
    cin>>n;
	cout<<"\nEnter Elements :";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"\nEnter threshold value :";
	cin>>k;
	for(i=0;i<n;i++)
	{
	 while(a[i]>0)
	 {
		a[i]-=k;
		c++;
     }
    }
	cout<<"\nTotal = "<<c;
}