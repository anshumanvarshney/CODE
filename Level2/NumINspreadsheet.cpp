/*
Given a column title as appears in an Excel Spreadsheet, return its corresponding column number.
For Example :

A -> 1
B -> 2
....
....
Z -> 26
AA -> 27
Input Format

One string denoting the column title of an excel spreadsheet.

Constraints

The answer will always fit in a 32-bit integer.

Output Format

Output an integer.

Sample Input 0

AA
Sample Output 0

27
*/

#include <bits/stdc++.h>
using namespace std;

//simple
/*
	int res,i,n;
        res=0;
        for(i=0;s[i];i++)
        {
            res*=26;
            res+=(s[i]-'A'+1);
        }
    
        return res;
		*/
long long int count(string a)
{
    long long int res=0,i;
    int n=a.length();
    if(n==1)
        return (a[i]-'A'+1);
     i=0;  
    while(i<n-1)
    {
       res+=(a[i]-'A'+1);
       res*=26;
       
       i++; 
     } 
    res+=(a[i]-'A'+1);
    return res;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string a;
    cin>>a;
    cout<<count(a);
    
    return 0;
}