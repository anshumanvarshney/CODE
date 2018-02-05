/*
4)

Given an array you have to find  the max sum of i*A[i] where i is the index 
of the array obtained by rotating the element of the array one by one . 
Your task is to complete the function max_sum which takes one argument 
which is the array A [ ] and returns an integer value denoting  the required max sum .

Example:
Input
1
4
8 3 1 2
Output
29

Explanation
Above the configuration possible by rotating elements are
3 1 2 8 here sum is 3*0+1*1+2*2+8*3 = 29
1 2 8 3 here sum is 1*0+2*1+8*2+3*3 = 27
2 8 3 1 here sum is 2*0+8*1+3*2+1*3 = 17
8 3 1 2 here sum is 8*0+3*1+1*2+2*3 = 11
Here the max sum is 29 */

/*in min time complexity
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,d,*a;
    cin>>n>>d;
	a=new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
	reverse(a,a+d);//0 to d-1
	reverse(a+d,a+n);//d to n-1
	reverse(a,a+n);//0 to n-1
	 for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}*/
#include<iostream>
using namespace std;

int main()
{
	int n,a[10],b[10],i,j,k,t,c,d=0;
	
	cout<<"\nEnter size of array :";
	cin>>n;
	cout<<"\nEnter Array :";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"\nArray is :";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	for(i=0;i<n;i++)
	{
		t=a[0];
		c=0;
		for(j=0;j<n-1;j++)
		{
			a[j]=a[j+1];
		}
		a[n-1]=t;
		cout<<"\nRotated Array "<<i+1<<" :  ";
		for(k=0;k<n;k++)
		{
			cout<<a[k]<<" ";
			c+=k*a[k];
			
		}
		cout<<"\nSum of array :"<<c;
        b[d]=c;
		d++;
	}
  cout<<"\nTotal sum :"<<c;
 int max=b[0];  
  for(i=0;i<d;i++)
  {
	  if(max<b[i])
	  {
		  max=b[i];
	  }
  }
  cout<<"\nMinimum sum = "<<max;
}

/*
#include<iostream>
using namespace std;

int main()
{
	int i,j,n,d,k,t;
	int *a;
	a=new int[n];
	cin>>n>>d;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<d;i++)
	{
		t=a[0];
		for(j=0;j<n-1;j++)
		{
		 a[j]=a[j+1];
		}
		a[n-1]=t;
	}
		for(k=0;k<n;k++)
		{
			cout<<a[k]<<" ";
		}
}
*/



