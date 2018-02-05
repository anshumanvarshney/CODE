/*
Given an array a[N], write a program that prints the maximum GCD (Greatest Common Divisor )
 of any subset of atleast size 2 the array.
Sample Input 0

7
6
12
24
3
15
36
10
Sample Output 0

12
Explanation 0

12 is the greatest GCD possible by considering the subset {12,24,36}.
*/
#include <bits/stdc++.h>
using namespace std;
//to find GCD
long long int gcd(int a, int b)
{
    if (a == 0 || b == 0)
       return 0;
 
    if (a == b)
        return a;
 
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
    
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int n,i,a[1000],t,m=INT_MIN,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n<2)
        cout<<-1;
    else
    {
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            t=gcd(a[i],a[j]);
            m=max(m,t);
        }
    }
    cout<<m;
    }
    return 0;
}

