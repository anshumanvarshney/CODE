#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
	char s[20];
	int i,j,k,a,b;
	cout<<"Enter string :";
	gets(s);
	for(i=0;s[i]!='\0';i++);
	cout<<"\nEnter two no :";
	cin>>a>>b;
	for(j=a;j<=b;j++)
	{
		for(k=j+1;k<b+1;k++)
		{
			if(s[j]>s[k])
			{
				int t = s[j];
				s[j]=s[k];
				s[k]=t;
			}
		}
	}
	cout<<"\nAlphabatically order :";
	for(i=a;i<=b;i++)
	{
		cout<<s[i]<<" ";
	}
}