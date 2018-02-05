/*
Check set bits
Given a number N. Write a program to check whether every bit in the binary representation of the given number is set or not.
Input:
3
7
14
4
Output:
YES
NO
NO
*/


#include<bits/stdc++.h>
using namespace std;

string count(int n)
{
    int sum=0,c=0;
    while(n!=0)
    {
        c++;
        sum+=n%2;
        n/=2;
    }
    if(sum==c)
        return "YES";
    else return "NO";    
}

int main()
 {
	//welcome Anshuman Varshney
	int p;
	cin>>p;
	while(p--)
	{
	    int n;
	    cin>>n;
	    cout<<count(n)<<"\n";
	}
	return 0;
}