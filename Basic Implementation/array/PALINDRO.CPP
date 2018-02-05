#include<iostream.h>
#include<conio.h>

int main()
{
 clrscr();
 int n,a,d,r=0;
 a=n;
 while(n!=0)
 {
  d=n%10;
  r=r*10+d;
  n=n/10;
 }
 cout<<"\nReverse :"<<r;
 if(a==r)
 cout<<"\npalindrom";
 else cout<<"\nille";
 getch();
 return 0;
}