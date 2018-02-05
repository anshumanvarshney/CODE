#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	char a[10],b[10];
	int i,j,k,n,m;
	gets(a);
	gets(b);
	for(m=0;a[m]!='\0';m++);
	for(n=0;b[n]!='\0';n++);
	
	for(j=0;j<n;j++,m++)
	{
		a[m]=b[j];
	}
    a[m]='\0';
	puts(a);
}
/*
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	char a[10],b[10];
	int i,j,k,n,m;
	gets(a);
	gets(b);
	for(m=0;a[m]!='\0';m++);
	for(n=0;b[n]!='\0';n++)
	{
		a[m]=b[n];
		m++;
	}
    a[m]='\0';
	puts(a);
}
*/