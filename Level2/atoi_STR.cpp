/*
Implement Atoi
Your task  is to implement the function atoi. The function takes a string(str) as argument and
 converts it to an integer and returns it.
  if the input string is not a numerical string then output will be -1. i.e if str=12a then output =-1
 
 char str[] = "89789";
 int val = myAtoi(str);
 printf ("%d ", val);
	
 o/p -> 89789
 
 
 Note : concept
 if you want to include integer value into char of string eg.as we include in runlength encoding then a[i]+'0'
 if you want to include char value into int  eg.this program then a[i]-'0'
 */
 
#include<bits/stdc++.h>
using namespace std;

int ato(string a)
{
	int c=0,t,sign=1;
	int n=a.length();
	if(n==0) return 0;
	int i=0;
	if(a[i]=='-')
	{
		sign=-1;
		i++;
	}
	for(;i<n;i++)
	{
		t=a[i]-'0';
		if(t>=0 && t<=9)
		{
			c=c*10 + t;
		}
		else return -1;
	}
	return c*sign;
}

int  main()
{
	string a;
	cin>>a;
	cout<<ato(a);
}