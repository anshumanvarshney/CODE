//time complexity =O(log(n)) base 2
//advantages no. of iteration reduce i.e at each n/2----
//disadvantages : works only on sorted array

#include<iostream>
using namespace std;

int main()
{
	int *a,i,n,x,f=0,l,m,h;
	cout<<"Enter size of the array :";
	cin>>n;
	a=new int [n];
   cout<<"\nEnter elements :";
   for(i=0;i<n;i++)
   {
	   cin>>a[i];
   }
   cout<<"\nEnter the element to be search :";
   cin>>x;
   l=0,h=n-1;
   while(l<=h)// condition
   {
	   m=(l+h)/2;
	   if(a[m]==x)
	   {
		   f=1;
		   break;
	   }
	   else if(a[m]<x)
	     l=m+1;
	   else if(a[m]>x) 
		 h=m-1;
   }
   if(f==0)
	   cout<<"\nNot found ";
   else
       cout<<"\nElement found at position :"<<m+1;
    
   delete []a;
}