#include<bits/stdc++.h>
using namespace std;

void disp(int (*a)[3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
  	   for(j=0;j<3;j++)
      	{
           	cout<<(*(*(a+i)+j));
      	}
	}
}

int main()
{
	int a[3][3],i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>(*(*(a+i)+j));
		}
	}
	disp(a);
}

