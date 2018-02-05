/*
GCD of Array

For a given array find out the GCD of the array.

1
5
4 7 5 6 3

o/p:
1
*/
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) 
{
    if(a==0 && b!=0)
        return b;
    if(b==0&&a!=0)
        return a;
    if(a==b)
        return a;
    if(a>b)
        return gcd(a-b,b);
    else return gcd(a,b-a);    
    
}
int main()
 {
	//welcome Anshuman Varshney
	int p,n,i;
	cin>>p;
	while(p--)
	{
    	cin>>n;
	    int a[100];
	    for(i=0;i<n;i++)
	        cin>>a[i];
	    int t=a[0];
	    for(i=1;i<n;i++)
	    {
	        t=gcd(t,a[i]);
	    }
	    cout<<t<<"\n";
	}
	
	return 0;
}