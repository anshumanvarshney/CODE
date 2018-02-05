/*
Barua has developed his own Operating System known as "Barua OS" ( BOS ). One day while booting up his 
system he runs into a bug. You want to impress Barua so you jump in and offer to solve the bug yourself.
Barua doesn't like binary numbers very much and his operating system uses a new number system called BNS 
( Barua Number System ). 
The following are the properties of a number represented in BNS form :

The number can only be made up of 2 distinct digits, one or zero.
The number cannot start with zero.
The number can have any number of zeroes, but only one instance of the digit one.
For example 100, 1000, 10000 are Barua Numbers whereas 101, 502, 625 are not Barua Numbers. 
Unfortunately one decimal number has crept into a list of Barua Numbers and Barua OS cannot find its product. Can you?

Sample Input 0

4
100
121
10
100

Sample Output 0
12100000


or another algo
if(n%10==0)
	sum+=log[n];//provide number of zeroes
else r=n;
print(r)
for(i=0;i<sum;i++)
	cout<<"0";

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int i,n,a[1000001],r=1,f=0,k;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
 
      for(i=0;i<n;i++)
      {
            k=a[i];
            while(k!=0)
            {
                if(k%10==0)
                {
                    k=k/10;
                    f++;
                }
                else
                {
                    if(k==1)//if k is barua
                        break;
                    else
                    {
                        r=k;//not barua
                        break;
                     }
                }
            }
      }
 
 
 cout<<r;
 for(i=0;i<f;i++)
 cout<<"0";
    return 0;
}


12100000
*/

