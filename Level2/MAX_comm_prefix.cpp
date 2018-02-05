/*
Longest Common Prefix of two strings is the longest possible string that is a prefix of both the strings.
Your task is to write a program that takes as input an array of strings and returns the longest common prefix 
for all the strings i.e. the longest string that is a prefix of every string in the array.

Sample Input 0

3
abcdefgh
aefghijk
abcefgh
Sample Output 0
a
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i,j,len,c,t,m=INT_MAX;
    cin>>n;
    string s[1000];
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
  
    int size=s[0].length();
 
    for(i=0;i<size;i++)
    {
        c=0;
        for(j=0;j<n;j++)
        {
            if(s[0][i]==s[j][i])
                c++;
            else break;
        }
        if(c==n)
            cout<<s[0][i];
        else break;
    }
    
    return 0;
}
