#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,*p,i,c=0,a[10];
	cout<<"Enter size :";
	cin>>n;
	p=new int [n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
    for(i=0;i<n;i++)
	{
		c+=pow(2,(n-i-1))*a[i];
	}
	cout<<c;
	
    delete [] p;
}