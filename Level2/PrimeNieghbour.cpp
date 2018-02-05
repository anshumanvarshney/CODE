/*
At least k prime numbers from 2 to n inclusively can be expressed as the sum of three integer numbers:
 two neighboring prime numbers and 1. 
For example, 19 = 7 + 11 + 1, or 13 = 5 + 7 + 1. 

Example
Input-1: 
27 2 
Output-1: 
YES 
Input-2: 
45 7 
Output-2: 
NO 
*/

#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n,int b[],int &c)
{
    int a[n] = {0};
 
    for (int i = 2; i < n; i++)
    {
        for (int j = i * i; j < n; j+=i)
        {
            a[j - 1] = 1;
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (a[i - 1] == 0)
            b[c++]=i;
    }
}

bool isprime(int n)
{
     if (n <= 1)  return false;
    if (n <= 3)  return true;

    for (int i=2; i*i<=n; i++)
        if (n%i == 0)
           return false;
 
    return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k,a[1000],c,count=0,i;
    cin>>n>>k;
    SieveOfEratosthenes(n,a,c);
    for(i=0;i<c-1;i++)
    {
        if(isprime(a[i]+a[i+1]+1) && (a[i]+a[i+1]+1) <n)
              count++;
    }
    if(count>=k)
        cout<<"YES";
    else cout<<"NO";
    return 0;
}
