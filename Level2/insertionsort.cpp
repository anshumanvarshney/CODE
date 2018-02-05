//complexity in all case except best case has O(n-1) ( worst best ..) O(n^2)
#include<iostream>
using namespace std;

void insertion_sort ( int A[ ] , int n) 
{
     for( int i = 0 ;i < n ; i++ ) {
    /*storing current element whose left side is checked for its 
             correct position .*/

      int temp = A[ i ];    
      int j = i;

       /* check whether the adjacent element in left side is greater or
            less than the current element. */

          while(  j > 0  && temp < A[ j -1]) {

           // moving the left side element to one position forward.
                A[ j ] = A[ j-1];   
                j= j - 1;
           }
         // moving current element to its  correct position.
           A[ j ] = temp;       
     }  
}

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
	int *a,i,n,j,k,t;
	cout<<"Enter size of the array :";
	cin>>n;
	a=new int [n];
   cout<<"\nEnter elements :";
   for(i=0;i<n;i++)
   {
	   cin>>a[i];
   }
  
   cout<<"\n\nInsertion sort :\n";
   sort(a,n);
   for(i=1;i<n;i++)   //take care of it 0 to n-1 and 1 to n;
   {
	   for(j=0;j<i;j++)  // from element i to leftmost element
	   {
		   if(a[j]>a[i])
		   {
			   t=a[j];
			   a[j]=a[i];
			   for(k=i;k>j;k--)
			   {
				   a[k]=a[k-1]; //shifting of each element to right by one position
			   }
			   a[k+1]=t;
		   }
	   }
	   sort(a,n);
   }
   delete []a;
}