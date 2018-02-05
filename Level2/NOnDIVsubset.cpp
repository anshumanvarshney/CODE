/*
Given a set, S, of n distinct integers, 
print the size of a maximal subset, S', of  where the sum of any 2 numbers in is not evenly divisible by k.

Input Format
The first line contains 2 space-separated integers,n  and k, respectively. 
Output Format
Print the size of the largest possible subset ().

Sample Input
4 3
1 7 2 4
Sample Output
3
*/

#include <bits/stdc++.h>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int n,maxx,c=0,k,a[100000],co[100000],i,sum=0,j;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a[i];
   
    for(i=0;i<n;i++)
    {
        co[a[i]%k]++;
    }
    sum+=(co[0]>0);//means if (c[0]>0) then take 1 only else if 0 then take 0
    i=1;
    j=k-1;
    while(i<j)
    {
       sum+=max(co[i],co[j]);
        i++;
        j--;
    }
    if (i == j) sum += (co[i] > 0);
    cout<<sum;
    
    return 0;
}
