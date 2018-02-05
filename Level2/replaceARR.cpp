/*
Given an array of integers, replace every element with the greatest element on the right side in the array.
Replace last element with 0 as there no element on the right side of it.
 
Note : O(n).

Sample Input 0
6
6 7 4 3 5 2

Sample Output 0

7 5 5 5 2 0 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long int n,a[100000],i,j,temp,max;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    
    temp=a[n-1];
    a[n-1]=0;
    
    for(i=n-2;i>=0;i--)
    {
        max=a[i];
        a[i]=temp;
        if(temp<max)
            temp=max;
        
    }
    
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";    
    return 0;
}
