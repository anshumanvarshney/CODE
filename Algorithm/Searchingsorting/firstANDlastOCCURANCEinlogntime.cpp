/*
int a[]={1,2,2,3,4,5,5,5,5,5,6,6,8}
cin>>x
first=5
last=9

hint use binary search
*/
#include<bits/stdc++.h>
using namespace std;

int fo(int a[],int l,int h,int e)
{
	int i,mid,result=-1;
	
	while(l<=h)
	{
		mid=(l+h)/2;
	    if(a[mid]==e)
		{
	        result=mid;
			h=mid-1;//because we need first occurance so traverse backward
		}
		else if(e<a[mid])
			h=mid-1;
		else l=mid+1;			
	}
	
	return result;
}

int lo(int a[],int l,int h,int e)
{
	int i,mid,result=-1;
	
	while(l<=h)
	{
		mid=(l+h)/2;
	    if(a[mid]==e)
		{
	        result=mid;
			l=mid+1;//because we need last occurance so traverse forward
		}
		else if(e<a[mid])
			h=mid-1;
		else l=mid+1;			
	}
	
	return result;
}
int main()
{
	int a[]={1,2,2,3,4,5,5,5,5,5,6,6,8};
	int n=sizeof(a)/sizeof(int);
	int x;
	cin>>x;
    int f =fo(a,0,n-1,x);
	int l =lo(a,0,n-1,x);
	if(f==-1)
		cout<<"\nElement not found";
	else cout<<"\nfirst occurance of the element :"<<f;
	if(l==-1)
		cout<<"\nElement not found";
	else cout<<"\nLast occurance of the element :"<<l;
	
	}