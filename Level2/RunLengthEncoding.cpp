/*
Run Length Encoding

Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
You are required to complete the function encode that takes only one argument the string 
which is to be encoded and returns the encoded string.

*/

#include<bits/stdc++.h>
using namespace std;

string rle(string a)
{
	int i,c=1,j=0;
	char t;
	string b="";
	t=a[0];
	b.push_back(t);
	for(i=1;i<a.length();i++)
	{
		if(t==a[i])
			c++;
		else
		{
			b.push_back(c+'0');//note to convert the number into char string
			t=a[i];
			b.push_back(t);
			c=1;
		}
	}
	b.push_back(c+'0');
	return b;
}

//C type
char *rle(char *a)
{
	int i,c=1,j=0,n;
	for(n=0;a[n]!='\0';n++);
	char t;
	char *b;
	b=new char[n*2+1];
	t=a[0];
	b[j++]=t;
	for(i=1;i<n;i++)
	{
		if(t==a[i])
			c++;
		else
		{
			
			b[j++]=c+'0';//note to convert the number into char string
			t=a[i];
			b[j++]=t;
			c=1;
		}
	}
	b[j++]=c+'0';
	b[j]='\0';
	return b;
}

int main()
{
	char a[]="wwwwwwaaaaaqqqqzzzz";
	char *b=rle(a);
	for(int i=0;i<b[i]!='\0';i++)
		cout<<b[i];
}