/*
Input:
  First List: 5 6 3  // represents number 563
  Second List: 8 4 2 //  represents number 842
Output
  Resultant list: 14 0 5  // represents number 1405
*/

#include<iostream>
using namespace std;

int main()
{
	int n,*a,*b,*sum,i,j;
	cin>>n;
	a=new int[n];
	b=new int[n];
	sum=new int[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(i=0;i<n;i++)
	{
		sum[i]=a[n-1-i]+b[n-1-i];
		if(sum[i-1]>9 && i!=0)
		{
			sum[i-1]%=10;
			sum[i]+=1;
		}
	}
	for(i=n-1;i>=0;i--)
	{
		cout<<sum[i]<<" ";
	}
	delete [] a;
	delete [] b;
	delete [] sum;
	return 0;
}