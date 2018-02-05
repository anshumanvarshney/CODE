//complexity in all case(except worst case = O(n^2) ..) O(logn) base 2 
//complexity in all case(except worst case = O(n^2) ..) O(logn) base 2 
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

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int split (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <high; j++)//low to high not like 0 to n-1
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);//don't put pivot here inplace of arr[high] because a[high] should also get a[i+1]
    return (i + 1);
}

void quicksort(int a[],int low,int up)
{
	if(up>low)//if(low>=up) then return because only one element remains // otherwise recursion done infinitely
	{
		int i=split(a,low,up);   //by this process left of pivot element has less than and right has greater no.
		//i has index of pivot element
		quicksort(a,low,i-1);  // one side 
		quicksort(a,i+1,up);   // other side
	}
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
   cout<<"\n\nQuick sort :\n";
   sort(a,n);
   quicksort(a,0,n-1);
   sort(a,n);
}
