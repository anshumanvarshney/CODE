/*
Sherlock considers a string, s, to be valid if either of the following conditions are satisfied:

All characters in s have the same exact frequency (i.e., occur the same number of times). 
For example,s="aabbcc"  is valid, but "baacdd" is not valid.
Deleting exactly 1 character from  will result in all its characters having the same frequency. 
For example, "aabbccc" & "aabbc" and  are valid because all their letters will have the same frequency if we remove  
occurrence of c, but "abcccc" is not valid because we'd need to remove 3 characters.
Given , can you determine if it's valid or not? 
If it's valid, print YES on a new line; otherwise, print NO instead.

Sample Input 0
aabbcd

Sample Output 0
NO

*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int c[100000],i;
    string s;
    memset(c,0,sizeof(c));
    cin>>s;
    for(i=0;i<s.size();i++)
        c[s[i]-'a']++;
    map<int,int> m;
    for(i=0;i<s.size();i++)
    {
         if (c[i] > 0)
         m[c[i]]++;   
    }
    int x,y,z,w,flag;
    map<int,int> ::iterator k;
    if(m.size()<=1)
        cout<<"YES";
    else if(m.size()>2)
        cout<<"NO";
    else
    {
        flag=0;
        x = (m.begin()->first);
        y = (m.begin()->second);
        z = (m.rbegin()->first);
        w = (m.rbegin()->second);
        if(x==1&&y==1)
            flag=1;
        else if(z==x+1&&w==1)
            flag=1;
   
        if(flag==1)
            cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
   
    return 0;
}
