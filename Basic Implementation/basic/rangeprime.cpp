#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int a,b,i,j,c;
	cout<<"\nEnter range. :";
	cin>>a>>b;
	for(j=a;j<=b;j++)
	{
		c=0;
	 for(i=2;i<j/2;i++)//for better time complexity /2
	 {
		if(j%i==0)
		{
			c++;
		}
	 }
		if(c==0&&j!=1)
			cout<<j<<" ";
	}
}