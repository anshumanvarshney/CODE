/*
Remove character
Given two strings s1 & s2, remove those characters from first string which are present in second string.
Both the strings are different and contain only lowercase characters.
 
Output:
Print the modified string(s1). For each test case, print the output in a new line.


 
 Input:
2
geeksforgeeks
mask
removeccharaterfrom
string

Output:
geeforgee

emovecchaaefom

simple if(a[i]==b[i])
	flag=1;
if(flag==0)
	a.push(s[i])
 
 or using hashing
 take second in set
 and use find function to clarify if it is present ot not
 
 */
 
#include<bits/stdc++.h>
using namespace std;

string rem(string a,string b)
{
	int n=a.length();
	int m=b.length();
	string c="";
	int i,j;
	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++)
		{
			if(a[i]!=b[j])
				c.push_back(a[i]);
		}
		if(c!=a)
		{
			a=c;
			n=a.length();
		}
		c="";
	}
	return a;
}

int main()
{
	int p;
	cin>>p;
	while(p--)
	{
		string a,b;
		cin>>a>>b;
		cout<<rem(a,b)<<"\n";
	}
}