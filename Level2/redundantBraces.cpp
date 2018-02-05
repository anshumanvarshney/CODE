/*
Write a program to validate if the input string has redundant braces?
Return 0/1 

0 -> NO 1 -> YES 

Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0
Some example of redundant braces -  (a*b)*((c*d)) , ((a+b)) , ((c) + d)   
*/

#include<bits/stdc++.h>
using namespace std;

string redundant(string s)
{
	stack<char> st;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!=')')
			st.push(s[i]);
		else
		{
			int c=0;
			while(!st.empty() && st.top()!='(')
			{
				st.pop();
				c++;
			}
			st.pop();
			if(c==0 || c==1)
				return "Yes";
		}
	}
	return "No";
}

int main()
{
	string s;
	cin>>s;
	cout<<redundant(s);
	return 0;
}