#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	char a[10],b[10];
	int i,j=0,k,n,m;
	gets(a);
	for(m=0;a[m]!='\0';m++);	
	for(i=0;i<m;i++)
	{
		if(a[i]!='a')
		{
			b[j]=a[i];
			j++;
		}
	}
	b[j]='\0';
	puts(b);
}