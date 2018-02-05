#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	char a[10],b[10],c[20];
	int i,j,k,n,m;
	gets(a);
	gets(b);
	for(m=0;a[m]!='\0';m++);
	for(n=0;b[n]!='\0';n++);
	
	for(i=0;i<m;i++)
	{
		c[i]=a[i];
	}
	for(j=0,k=m;j<n;j++,k++)
	{
		c[k]=b[j];
	}
    c[k]='\0';
	puts(c);
}