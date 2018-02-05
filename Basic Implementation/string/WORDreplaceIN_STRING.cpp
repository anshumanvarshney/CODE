#include<bits/stdc++.h>

using namespace std;


int main()
{
	char a[100],b[100],c[100],d[100];
	int n,m,l,i,k=0,j=0;
	cout<<"\nEnter the text :";
	cin.getline(a,100);
	cout<<"\nEnter the pattern to be replaced :";
	cin.getline(b,100);
	cout<<"\nEnter the replaced pattern :";
	cin.getline(c,100);
	cout<<"\nAfter Replacement : ";
	for(n=0;a[n]!='\0';n++);
	for(m=0;b[m]!='\0';m++);
	for(l=0;c[l]!='\0';l++);
	for(i=0;i<n;i++)
	{
		if(a[i]==b[j])
		{
			d[i]=c[j];
			j++;
		}
		else d[i]=a[i];
	}
	d[i]='\0';
	
    cout<<d;
	return 0;
}