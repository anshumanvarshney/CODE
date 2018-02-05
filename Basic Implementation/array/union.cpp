/*
Algo :
k,i,j ==0;
while(i<=n && j<=n)
{
		if(a[i]>a[j])
		{
			c[k]=a[i];
			i++,k++;
		}
		else
			if(a[i]==b[i])
			{
				c[k]=a[i];//c[k]=b[j];
				i++,k++,j++;
			}
			else{
				c[k]=a[j]
				k++,j++;
			}
}
while(i<=n)
{
	c[k]=a[i]
	i++,k++;
}
while(j<=n)
{
	c[k]=a[i]
	j++,k++;
}
}
*/

#include<iostream>
using namespace std;
void get(int []);
void fn(int [],int []);
void fn1(int [],int []);
void show();
int main()
{
	int a[10],b[10],i,j;
	get(a);
	get(b);
	fn(a,b);
	fn1(b,a);
	show();
}
int i,j,k=0,p,c[10];
void get(int a[])
{
	for(i=0;i<5;i++)
		cin>>a[i];
}
void fn(int a[],int b[])
{
	for(i=0;i<5;i++)
	{
		p=0;
	 for(j=0;j<5;j++)
	 {
	  if(a[i]==b[j])
	  {
		 p++;		 
	  }
	 }
	 if(p==0||p==1)
	 {
		 c[k]=a[i];
		 k++;
	 }
	}
}
void fn1(int a[],int b[])
{
	for(i=0;i<5;i++)
	{
		p=0;
	 for(j=0;j<5;j++)
	 {
	  if(a[i]==b[j])
	  {
		 p++;		 
	  }
	 }
	 if(p==0)
	 {
		 c[k]=a[i];
		 k++;
	 }
	}
}
void show()
{
	for(i=0;i<k;i++)
		cout<<c[i];
}