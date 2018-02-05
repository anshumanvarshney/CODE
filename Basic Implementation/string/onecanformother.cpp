#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	char a[10],b[10];
	int i,j,n,m;
	cout<<"\nEnter string 1 :";
	gets(a);

	cout<<"\nEnter string 2 :";
	gets(b);
	for(n=0;a[n]!='\0';n++);
	for(m=0;b[m]!='\0';m++);
	j=0;
	for(i=0;i<n;i++)
	 {
		 if(a[i]==b[j])
		 {
			j++;
		 }
	}
	if(j==m)
		cout<<"\nOne can form from other";
	else cout<<"\nnOne cannot form from other";
}