/*
You are given an array of N integers which is a permutation of the first N natural numbers. 
You can swap any two elements of the array. 
You can make at most K swaps. What is the largest permutation, in numerical order, you can make?

Sample Input 0

5 1
4 2 3 5 1
Sample Output 0

5 2 3 4 1
*/

#include <bits/stdc++.h>
using namespace std;

int maxx(long long int a[],long long int s,long long int n)
{
    int m=a[s],ind=s;
    for(int i=s;i<n;i++)
    {
        if(m<a[i])
        {
            m=a[i];
            ind=i;
        }
    }
    return ind;
}
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int n,k,a[100000],b[100000],i,j,t,index;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a[i];
       
    for(i=0;i<k;i++)
    {
        index=maxx(a,i,n);
        swap(a[i],a[index]);
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";     
    }
    
    return 0;
}
