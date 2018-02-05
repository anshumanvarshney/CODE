#include<iostream>
using namespace std;

void get(int [],int);
void fn(int [],int,int [],int,int []);
void sort(int []);
void show(int []);
int main()
{
 int a[10],b[10],d[10],n,m;
 cout<<"\nEnter how many no. you want to enter :" ;
 cin>>n;
 get(a,n);
 cout<<"\nEnter how many no. you want to enter :" ;
 cin>>m;
 get(b,m);
 cout<<"\nComplement of (A intersection B): " ;
 fn(a,n,b,m,d);
 fn(b,m,a,n,d);
 sort(d);
 show(d);
 return 0;

}
void get(int a[],int n)
{
 cout<<"\nEnter no :";
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
}
int k=0;
int p=0;
void fn(int a[],int n,int b[],int m,int d[])
{
 for(int i=0;i<n;i++)
 {
  int c=0;
  for(int j=0;j<m;j++)
  {
   if(a[i]!=b[j])
   {
    c++;
    if(c==m)
     {
      d[k]=a[i];
      cout<<d[k]<<" ";
      k++;
      p++;
     }
   }
  }

 }

}

/*
for(int i=0;i<n;i++)
 {
  int c=0;
  for(int j=0;j<m;j++)
  {
   if(a[i]==b[j])
   {
    c=2;
   }
   if(c!=2)
     {
      d[k]=a[i];
      cout<<d[k]<<" ";
      k++;
      p++;
     }
   }
  }

 }
*/

void sort(int d[])
{
 for(int i=0;i<p;i++)
 {
  for(int j=i+1;j<p;j++)
  {
   if(d[i]>d[j])
   {
    int t=d[i];
    d[i]=d[j];
    d[j]=t;
   }
  }
 }
}

void show(int d[])
{
 cout<<"\nAfter soring :";
 for(int i=0;i<p;i++)
 {
  cout<<d[i]<<" ";
 }
}