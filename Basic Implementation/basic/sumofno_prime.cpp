#include<iostream>
using namespace std;
int prime(int n)
{
	int i,c=0;
	for(i=2;i<=n/2;i++)
	 {
		if(n%i==0)
		{
			c++;
		}
	 } 
	 return c;
}
int main()
{
	int n,i,flag=0;
	cout<<"Enter a number :";
	cin>>n;
	for(i=2;i<n/2;i++)
	{
		if(prime(i)==0)
		{
			if(prime(n-i)==0)  // i+ n- i= n
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==1)
	    cout<<"\nYes";
    else 
		cout<<"\nNo";
}