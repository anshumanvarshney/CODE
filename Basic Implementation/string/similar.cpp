#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
	char a[200],b[200];
	gets(a);
	gets(b);
	if(strcmp(a,b)==0)
	{
		cout<<"similar";
	}
	else cout<<"No";
}

/*
without using string function

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
	char a[200],b[200];
	gets(a);
	gets(b);
	int i,j,c=0;
	for(i=0;a[i]!='\0';i++);
	for(j=0;b[j]!='\0';j++);
	if(i==j)
	{
		for(i=0;a[i]!='\0';i++);
		{
			if(a[i]!=b[i])
			{
				c++;
			}
		}
		
	if(c==0)
	cout<<"similar";
	}
	else cout<<"No";
}
*/