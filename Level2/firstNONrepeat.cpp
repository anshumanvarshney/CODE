/*
Non Repeating Character
Given a string s consisting of lowercase Latin Letters, find the first non repeating character in s.
Example:
Input :

3
5  
hello
12
zxvczbtxyzvy
6
xxyyzz

 

Output :

h
c
-1
*/
#include<bits/stdc++.h>
using namespace std;

void check(string a,int n)
{
    int index=-1,i,j;
    int count[1000];
    memset(count,0,sizeof(count));
    for(i=0;i<n;i++)
    {
	    count[a[i]]++;
    }
    for(i=0;i<n;i++)
    {
        if(count[a[i]]==1)
        {
            index=i;
            break;
        }
    }
    if(index==-1)
        cout<<-1<<"\n";
    else cout<<a[index]<<"\n";
}

int main()
{
    int p,n;
    string a;
    cin>>p;
    while(p--)
    {
        cin>>n;
        cin>>a;
        check(a,n);
        //cout<<a[t]<<
    }
	return 0;
}