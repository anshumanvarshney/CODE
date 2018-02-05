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
  
   cout<<"\n\nSelection sort :\n";
   sort(a,n);
   for(i=0;i<n-1;i++)
   {
	   for(j=i+1;j<n;j++)
	   {
		   if(a[i]>a[j])
		   {
			 int  t=a[i];
			   a[i]=a[j];
			   a[j]=t;
		   }
	   }
	   sort(a,n);
   }
}