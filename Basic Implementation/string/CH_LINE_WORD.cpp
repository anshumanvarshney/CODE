#include<bits/stdc++.h>

using namespace std;


int main()
{
	char a[100];
	cout<<"\nEnter the text :";
	cin.getline(a,100);
	int i,n,b=0,c=0,d=0;
	for(n=0;a[n]!='\0';n++);
	for(i=0;i<n;i++)
	{
		if((a[i]>='a' && a[i]<='z')||(a[i]>='A' && a[i]<='Z'))
			b++;
		if(a[i]==' ')//Note
			c++;
		if(a[i]=='\n')//Note
			d++;
	}
	cout<<"\nWord :"<<c+1;
	cout<<"\nLines :"<<d+1;
	cout<<"\nCharcter :"<<b;
    return 0;
}
