/*

You are given a task to find the sum of Products of corresponding elements of two arrays of the same size.
Given that k modifications are allowed on the first array, what is the minimum product that can be obtained? 
In each modification, one array element of the first array can either be increased or decreased by 2.

Note- the product sum is Summation (A[i]*B[i]) for all i from 1 to n where n is the size of both arrays

Sample Input 0

3 5
1 2 -3
-2 3 -5
Sample Output 0

-31
Sample Input 1

5 3
2 3 4 5 4
3 4 2 3 2
Sample Output 1

25
*/

#include <bits/stdc++.h>
using namespace std;


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int n,a[100000],b[100000],k,i,j,max,pos,sum=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        cin>>b[i];
    
   	max=INT_MIN;
	for(i=0;i<n;i++)
	{
		if(max<abs(b[i]))
		{
			max=abs(b[i]);
			pos=i;
		}
    }
   
    if(a[pos]<0)
    {
        while(k--)
            a[pos]+=2;
    }
    else
    {
        while(k--)
            a[pos]-=2;
    }
    for(i=0;i<n;i++)
    {
        sum+=a[i]*b[i];
    }
    
   cout<<sum;
   
    return 0;
}