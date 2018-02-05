/*
Given a non-negative number represented as an array of digits,
add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the list.

Example: 

Input:
2
4
5 6 7 8
3
9 9 9
Output:
5 6 7 9
1 0 0 0 
*/
/*
#include<bits/stdc++.h>
using namespace std;
//mine solution but it hold only integer limit 
int main()
{
	int p,n,n1,i,*a,j,k,l,m;
	//cout<<"\nEnter no. of test case :";
	cin>>p;
	for(i=0;i<p;i++)
	{
		//cout<<"\nEnter no. of elements :";
		cin>>n1;
		a=new int[n1];
		//cout<<"\nElements :";
		for(j=0;j<n1;j++)
		{
			cin>>a[j];
		}
		int r=0,*b;
		for(k=0;k<n1;k++)
		{
			r=r*10+a[k];
		}
		r+=1;
		b=new int[n1+1];
		l=0;
		while(r!=0)
		{
			b[l++]=r%10;
			r/=10;
		}
		for(m=l-1;m>=0;m--)
		{
			cout<<b[m]<<" ";
		}
	}

	return 0;
}
*/
#include <iostream>
using namespace std;
 
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
		{
	        cin>>a[i];
	    }
	    int x=a[n-1]+1;
	    int carry=x/10;
	    a[n-1]=x%10;
	    for(int i=n-2;i>=0;i--)
		{
	        x=(a[i]+carry);
	        a[i]=x%10;
	        carry=x/10;
	    }
	    while(carry!=0)
		{
	        cout<<carry%10<<" ";
	        carry/=10;
	    }
	    for(int i=0;i<n;i++)cout<<a[i]<<" ";
	    cout<<endl;
	}
	return 0;
}