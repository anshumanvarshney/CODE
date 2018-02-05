#include<iostream>
#include<string.h>
using namespace std;

int main()
{
 char a[10];
 int sum=0,i;
 cout<<"\nEnter your name :";
 gets(a);
 for( i=0;a[i]!=NULL;i++)
 {
  sum+=a[i];
 }
 cout<<sum;
 getch();
 return 0;
}