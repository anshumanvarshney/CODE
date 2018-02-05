#include<bits/stdc++.h>
using namespace std;
//iterative mine
int gcd(int a,int b)
{
	int b1=b,a1=a;
	while(a!=0)
	{	
		a=b%a;
		b=a1;
		a1=a;
		b1=b;
	}
	return b;
	
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
}

/*
int main()
{
	int r,a,b,q,mx,mn;
	cout<<"Enter two no : ";
	cin>>a>>b;
	mx=(a>b)?a:b;
	mn=(a<b)?a:b;
	//iterative
	while(mx!=0)
	{
	 a=mx%mn;//b%a
	 if(a==0)
	 {
		cout<<"\nHCF :"<<mn;//b
		break;
	 }
	 else
	 {
		 mx=mn;
		 mn=a;
	 }	
    }
}
*/

