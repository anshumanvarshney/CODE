#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;

void reverse(char *s,int n)
{
	int i;
	stack<char> st;
	for(i=0;i<n;i++)
	{
		st.push(s[i]);
	}
	for(i=0;i<n;i++) //or you can use empty function 
	{
		s[i]=st.top();      // char data=st.top; cout<<data; st.pop ; then no need to puts in the main function
		st.pop();
	}
}
int main()
{
	char s[10]; // or you can use string s; cin>>s
	int i;
	cout<<"\nEnter String :";
	gets(s);
	for(i=0;s[i]!='\0';i++);//length of string
	reverse(s,i);
	puts(s);
}