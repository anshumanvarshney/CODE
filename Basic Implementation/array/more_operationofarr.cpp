#include<iostream>
using namespace std;

/*
deletion from sorted array

int main()
{
	int *a,c=0,n,x,i,j;
	a=new int[100];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"\nEnter no. to be deleted :";
	cin>>x;
	for(j=0;a[j]<=x;j++);
	for(i=j-1;i<n;i++)
		a[i]=a[i+1];
	for(i=0;i<n-1;i++)
		cout<<a[i]<<" ";
	delete [] a;
}
*/
/*

Insertion in sorted array

int main()
{
	int *a,c=0,n,x,i,j;
	a=new int[100];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"\nEnter no. to be inserted :";
	cin>>x;
	for(j=0;a[j]<=x;j++);
	for(i=n;i>=j;i--)
	{
		a[i]=a[i-1];
	}
	a[j]=x;
	for(i=0;i<=n;i++)
		cout<<a[i]<<" ";
	delete [] a;
}

*/


/*

i/p = 2 3 0 9
o/p=9023 
a no.
 
int main()
{
	int *a,c=0,n,i,j;
	cin>>n;
	a=new int[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=n-1;i>=0;i--)
	{
		c=c*10+a[i];
	}
	cout<<c;
	delete [] a;
}
*/
/*
interchange largest and smallest no in an array

int main()
{
	int *a,n,i,j;
	cin>>n;
	a=new int[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	int pmin=0,pmax=0;
	int min=a[0];
	int max=a[0];
    for(i=0;i<n;i++)
	{
		if(min>a[i])
		{
			min=a[i];
			pmin=i;
		}
		if(max<a[i])
		{
			max=a[i];
			pmax=i;
		}
	}
	int t=a[pmin];
	a[pmin]=a[pmax];
	a[pmax]=t;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	delete [] a;
}

*/

/*

Array contains duplicate elements

int main()
{
	int *a,n,i,j;
	cin>>n;
	a=new int[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]==a[j] && i!=j)
			{
				cout<<"\nFound at position " <<i<<" and "<<j;   
			}
		}
	}
	delete [] a;
}
*/

/*
Second largest element

int main()
{
	int *a,n,i,j;
	cin>>n;
	a=new int[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	int max=a[0];
	int pos=0;
	
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			pos =i;
		}
	}
	int mx=a[0];
	int ps=0;
	for(i=0;i<n;i++)
	{
		if(( mx < a[i] ) && (a[i]!=max))
		{
			mx=a[i];
			ps=i;
		}
	}
	cout<<"Found at pos "<<ps+1<<" element = "<<a[ps];
delete [] a;
}

*/

