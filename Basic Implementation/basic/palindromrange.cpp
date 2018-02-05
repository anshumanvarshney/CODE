#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int x,y,i,a,d,r;
	cin>>x>>y;
	for(i=x;i<=y;i++)
	{	
	 a=i;
	 r=0;
	 while(a!=0)
    	{
		d=a%10;
		r=r*10+d;
		a=a/10;
	   }
	 if(r==i)
	 cout<<i<<" ";
	}
}



