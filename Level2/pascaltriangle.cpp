/*
1 
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/

#include <bits/stdc++.h>

using namespace std;
 
int main()
{
	int i,j,a[5][5]={0};//take long long for handling large values
	for(i=0;i<5;i++)
	{
		a[i][i]=a[i][0]=1;
		for(j=1;j<=i;j++)
		{
			a[i][j]=a[i-1][j-1]+a[i-1][j];	
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[i][j]!=0)
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
    return 0;
}
