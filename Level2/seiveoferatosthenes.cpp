/*
Sieve of Eratosthenes
Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.
For example, if n is 10, the output should be “2, 3, 5, 7”. If n is 20, the output should be “2, 3, 5, 7, 11, 13, 17, 19”.

The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than
 10 million or so (Ref Wiki).
*/
//concept bro
#include<bits/stdc++.h>
using namespace std;

const int len = 100;
 
int main()
{
	
	int n;
	cin>>n;
    int a[n] = {0};//all element are zero
 
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
            cout << i << "\t";
    }
}
//to find prime in a efficient way
bool isprime(int n)
{
     if (n <= 1)  return false;
    if (n <= 3)  return true;

    for (int i=2; i*i<=n; i++)
        if (n%i == 0)
           return false;
 
    return true;
}

//best algo for prime log(n)
bool isprime(int n)
{
    if(n<2)
        return false;
    else if(n<=3)
        return true;
    else if(n%2==0 || n%3==0)
        return false;
    for(int i=5;i*i<=n;i+=6)
    {
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}
//factor concept in less than O(n)

void isprime(int num)
{
    int result = 0;
	cout<<1
    for (int i=2; i<=sqrt(num); i++)
    {
        if (num%i==0)
        {
            if (i==(num/i))
                cout<< i;
            else
                cout<<i<<" "<<num/i;
        }
    }
}