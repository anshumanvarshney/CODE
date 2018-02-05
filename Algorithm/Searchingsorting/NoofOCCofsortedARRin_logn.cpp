/*
Given a sorted array of integers, find the number of occurrences of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

**Example : **
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.


Algo :

find first ocuurance
then find last occurance 
then l-f= required answer
*/
#include<bits/stdc++.h>
using namespace std;

int flo(int a[],int l,int h,int e,bool flag)
{
	int i,mid,result=-1;
	
	while(l<=h)
	{
		mid=(l+h)/2;
	    if(a[mid]==e)
		{
	        result=mid;
			if(flag)	
				h=mid-1;//find first ocuurence
			if(!flag)
				l=mid+1;//find last occurence
		}
		else if(e<a[mid])
			h=mid-1;
		else l=mid+1;			
	}
	
	return result;
}

int main()
{
	int a[]={1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 7, 7, 8, 8, 8, 8, 9, 9, 10, 10, 10 };
	int n=sizeof(a)/sizeof(int);
	int x;
	cin>>x;
    int f =flo(a,0,n-1,x,true);
	int l =flo(a,0,n-1,x,false);
	if(f==-1)
		cout<<"\nElement not found";
	else cout<<"\nfirst occurance of the element :"<<f;
	if(l==-1)
		cout<<"\nElement not found";
	else cout<<"\nLast occurance of the element :"<<l;
	cout<<"\nNo. of times occurence :"<<(l-f+1);
	
	}