/*
The string "GOTISPATHETIC" is written in a zigzag pattern on a given number of rows like this:

G---S---H---C-
-O-I-P-T-E-I--
--T---A---T---
And then read line by line: GSHCOIPTEITAT

Write the code that will take a string and make this conversion given a number of rows.
Sample Input 0

GOTISPATHETIC
3
Sample Output 0

GSHCOIPTEITAT
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string s;
    int n,zig=0,flag,i;
    cin>>s>>n;
    string res[n];
    for(i=0;s[i];i++)
    {
        res[zig].push_back(s[i]);
        if(zig==0)
            flag=1;
        else if(zig==n-1)
            flag=0;
        if(flag==0)
            zig-=1;
        else zig+=1;
    }
    for(i=0;i<n;i++)
        cout<<res[i];
    return 0;
}
