/*
Write a program to print the value of (AB) % M, given the values of A, B and M.

Remember, those who use an O(B) function to find the value of AB are scum. 
But whose who use the inbuilt library function to find the value of AB and then do %M are worse than scum.

Constraints
1 <= A, B, M <= 1012

Sample Input 0
2 3 3
Sample Output 0
2
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long int p,b,m,a;
    cin>>p>>b>>m;
    long long int res=1;
    a=p%m;
    while(b>0)
    {
        if(b%2!=0)
            res=(res*a)%m;
        b=b/2;
        a=(a*a)%m;
    }
    cout<<res%m;
    return 0;
}
