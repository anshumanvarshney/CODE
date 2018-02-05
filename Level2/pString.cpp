/*
A string is called a pString if it can be represented as p concatenated copies of some string. For example, the string
 "aabaabaabaab" is at the same time a 1String, a 2String and a 4String, but it is not a 3String,
 a 5String, or a 6String and so on. Obviously any string is a 1String.

You are given a string s, consisting of lowercase English letters and a positive integer p. 
Your task is to find if it is possible to reorder the letters in the string s in such a way that the resulting 
string is a pString.

Sample Input 0

2
aazz
Sample Output 0

YES
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int count[10000],p,i;
    string s;
    memset(count,0,sizeof(count));
    cin>>p;
    cin>>s;
    int flag=1;
    for(i=0;i<s.length();i++)
    {
        count[s[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(count[i]!=0)
        {
            if(count[i]%p!=0)
                flag=0;
        }
    }
    if(flag==1)
        cout<<"YES";
    else cout<<"NO";
    return 0;
}
