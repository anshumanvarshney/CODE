#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
int a[10],b[10],c[10],j;
for(int i=0;i<3;i++)
{
 cout<<"\nEnter Element A :";
 cin>>a[i];
}
for( i=0;i<3;i++)
{
 cout<<"\nEnter Element B :";
 cin>>b[i];
}
for(i=0,j=3;i<3;i++,j++)
{
 c[i]=a[i];
 c[j]=b[i];
}
cout<<"Array after Merging :";
for(i=0;i<6;i++)
{
 cout<<c[i];
 }
 getch();
 return 0;
}