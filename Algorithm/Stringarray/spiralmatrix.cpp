#include<bits/stdc++.h>
using namespace std;
const int MAX=100;
void printspiral(int a[][MAX],int n)
{
    int s=n/2,i,j,k,l,m;
    for(i=0;i<s;i++)
	{
		for(j=i;j<n-1-i;j++)
			cout<<a[i][j]<<" ";
		for(k=i;k<n-1-i;k++)
			cout<<a[k][n-1-i]<<" ";
		for(l=n-1-i;l>=i+1;l--)
			cout<<a[n-1-i][l]<<" ";
		for(m=n-1-i;m>=i+1;m--)
			cout<<a[m][i]<<" ";
	}	
	if(n%2!=0)
	{
		cout<<a[s][s];
	}
	cout<<"\n";
}
int main()
{
    int p,i,j;
    cin>>p;
    int a[MAX][MAX];
    while(p--)
    {
	    for(i=0;i<4;i++)
	    {
		    for(j=0;j<4;j++)
		    {
			    cin>>a[i][j];
		    }
	    }
	    printspiral(a,4);
    }
	return 0;
}