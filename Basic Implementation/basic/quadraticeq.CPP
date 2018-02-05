#include<iostream.h>
#include<conio.h>
#include<math.h>

int main()
{
 clrscr();
 int a,b,c,d,e;
 cout<<"\nEnter the coffecient of x^2 :";
 cin>>a;
 cout<<"\nEnter the coffecient of x :";
 cin>>b;
 cout<<"\nEnter constant :";
 cin>>c;
 d= (-b+sqrt(b*b-4*a*c))/(2*a) ;
 e= (-b-sqrt(b*b-4*a*c))/(2*a) ;
 cout<<"\nRoots are:"<<d<<" "<<e;

 getch();
 return 0;
}