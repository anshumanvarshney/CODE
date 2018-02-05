//complexity in all case(worst best ..) O(n^2)
#include<iostream>
using namespace std;

void sort(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
   {
	   cout<<a[i]<<" ";
   }
   cout<<"\n";
}
int main()
{
	int *a,i,n,j;
	cout<<"Enter size of the array :";
	cin>>n;
	a=new int [n];
   cout<<"\nEnter elements :";
   for(i=0;i<n;i++)
   {
	   cin>>a[i];
   }
  
   cout<<"\n\nBubble sort :\n";
   sort(a,n);
   for(i=0;i<n-1;i++)
   {
	   for(j=0;j<n-1-i;j++)
	   {
		   if(a[j]>a[j+1])
		   {
			 int  t=a[j];
			   a[j]=a[j+1];
			   a[j+1]=t;
		   }
	   }
	   sort(a,n);
   }
}