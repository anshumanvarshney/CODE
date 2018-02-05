#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	char a[10],b[10];
	int i,j,k,n,m;
	gets(a);
	for(m=0;a[m]!='\0';m++);	
	for(i=0;i<m;i++)
	{
		b[i]=a[i];
	}
	b[i]='\0';   // it is very important
	puts(a);
	puts(b);
}

/*
or without using for loop

#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	char a[10],b[10];
	int i,j,k,n,m;
	gets(a);
	for(m=0;a[m]!='\0';m++)
		b[m]=a[m];
	
	b[m]='\0';   // it is very important
	puts(a);
	puts(b);
}
*/