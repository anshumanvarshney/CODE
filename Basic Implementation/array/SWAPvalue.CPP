#include<iostream>
using namespace std;
int main()
{
int a[10],i,j;
for(i=0;i<4;i++)
{
 cout<<"\nEnter Element :";
 cin>>a[i];
}
for(i=0,j=3;i<j;i++,j--)
{
 int t=a[i];
 a[i]=a[j];
 a[j]=t;
}
cout<<"Array after swapping / reversing:";
for(i=0;i<4;i++)
{
 cout<<a[i]<<" ";
}
return 0;
}
/*output of swap and reverse is same in case of array