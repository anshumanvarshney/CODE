/*
Given a string, find the smallest string that can generate the original string by concatenation. 
See example case for clarity.

Sample Input 0

abababab
Sample Output 0

ab
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    string s,r1,res,r2;
    int i,n;
    cin>>s;
    n=s.length();
    for(i=1;i<=n;i++)
    {
        res="";
        r2="";
        r1="";
        
        res.assign(s,0,i);
        r2=res;
        while(r1!=s && r1.length()<s.length())
        {
            r1+=res;
        }
        if(s==r1)
            break;
    }
    cout<<r2<<"\n";
    return 0;
}