#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s[10],t;
	int n,i,j;
	cout<<"Enter no. of strings :";
	cin>>n;
	for(i=0;i<n;i++)
	{
		getline(cin, s[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			 if(s[i] > s[j])
			{
				t = s[i];
				s[i] = s[j];
				s[j] = t;
			}
	    }
	}		
	for(i=0;i<n;i++)
	{
		cout<<s[i]<<" ";
	}
}

/*
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[10][10],t[10];
	int n,i,j;
	cout<<"Enter no. of strings :";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(s[i],s[j])>0)
			{
			strcpy(t,s[i]);
			strcpy(s[i],s[j]);
			strcpy(s[j],t);
		    }
	    }
	}		
	for(i=0;i<n;i++)
	{
		cout<<s[i]<<" ";
	}
}

*/