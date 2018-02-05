#include<iostream.h>
#include<conio.h>

int main()
{
 clrscr();
 int a,b,c,n;
 a=0;
 b=1;
 cout<<"Enter the last number :";
 cin>>n;
 cout<<a<<" "<<b<<" ";
 while((a+b)<n)
 {
   c=a+b;
   cout<<c<<" ";
   a=b;
   b=c;

 }
 getch();
 return 0;
}