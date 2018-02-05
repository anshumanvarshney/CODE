/*
Examples:

Input:  arr[] = {10, 12, 11};
Output: Length of the longest contiguous subarray is 3

Input:  arr[] = {14, 12, 11, 20};
Output: Length of the longest contiguous subarray is 2

Input:  arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
Output: Length of the longest contiguous subarray is 5

Algo first

Sort array
check for next element
count++
if(max<count)
	 max=count;

 return max
 
 second algo written here
*/
#include<bits/stdc++.h>
using namespace std;
/*
int main()
{
	int a[]={10, 12, 11};
	int n=sizeof(a)/sizeof(int);
	sort(a,a+n);
	int j,c=0,k=0,b[10];
	
	for(j=0;j<n;j++)
	{
			if(a[j]+1==a[j+1])
			{
				c++;
				continue;
			}
			b[k++]=c+1;
			c=0;
	}
	int m=b[0];
	for(j=0;j<k;j++)//maximum concept
	{
		if(m<b[j])
		{
			m=b[j];
		}
	}
	cout<<m;
}
*/
//efficient solution
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={14, 12, 11, 20};
	int n=sizeof(a)/sizeof(int);
	sort(a,a+n);
	int j,c=1,max=0;
	for(j=0;j<n;j++)
	{
			if(a[j]+1==a[j+1])
			{
				c++;
				continue;
			}
			if(max<=c)
			{
				max=c;
			}
			c=1;
	}
	cout<<max;
}