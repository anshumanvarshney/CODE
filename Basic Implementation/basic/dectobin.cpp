#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,a[10];
	cout<<"Enter No :";
	cin>>n;
	int i,k=0;
	while(n>0)
	{
		
		a[k]=n%2;
		n/=2;
		k++;
	}
	
	for(i=k-1;i>=0;i--) // don't use i=k;i>0;i-- coz it takes garbage value
	{
		cout<<a[i];
	}
}
