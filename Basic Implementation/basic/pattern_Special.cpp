/*
1
232
34543
4567654
567898765
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9};
	int i,j,k=-1,l;
	for(i=0;i<5;i++)
	{
		k++;
		for(j=i;j<=i+k;j++)
			cout<<j;
		for(l=j-2;l>=i;l--)
			cout<<l;
		cout<<"\n";
	}
} 
//without array
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k=1,x=1,p;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=i;j++)
		{
			cout<<k<<" ";
			k++;
		}
		if(i!=1)
			k--;
		p=k-1;
		x++;
		k=x;
		while(p>=i&&i!=1)
		{
			cout<<p<<" ";
			p--;
		}
		cout<<"\n";
	}
}
