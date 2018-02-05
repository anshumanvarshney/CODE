/*
Toyland unlike Earth has only 26 chemical elements known as of now. Each element is identified as a 
lowercase English letter in range ‘a’ - ‘z’. Every chemical compound is composed of these given chemical 
elements only. A chemical element is special if it is present in all the given compounds.

You are given a list of N chemical compounds. Print the number of special chemical elements.

Sample Input 0

4
abbbc
xbady
bghla 
aba
Sample Output 0

2
*/


#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,c[100],count=0,a;
   
    cin>>n;
     a=n;
    string s,res;
    while(n--)
    {
        cin>>s;
        sort(s.begin(),s.end());
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=s[i+1])
                res.push_back(s[i]);
        }
    }
    sort(res.begin(),res.end());
    memset(c,0,sizeof(c));
    for(int i=0;i<res.length();i++)
        c[res[i]-'a']++;
    for(int i=0;i<26;i++)
    {
        if(c[i]==a)
            count++;
    }
    cout<<count;
    return 0;
}
