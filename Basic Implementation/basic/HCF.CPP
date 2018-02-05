#include<iostream.h>
#include<conio.h>

int main()
{
 clrscr();
 /*int a,b,max;
 cout<<"Enter two no :";
 cin>>a>>b;
 while(a!=b)
 {
  if(a>b)
  a-=b;
  else
  b-=a;
 }
 cout<<"\nHCF :"<<a;//or b;*/
 // (or)
 int a,b,max;
 cout<<"Enter two no :";
 cin>>a>>b;
 max=(a>b)?a:b;
 while(max<=(a*b))
 if(a%max==0&&b%max==0)
 {

  cout<<"\nHCF :"<<max;
  break;
 }
 else max--;
 getch();
 return 0;
}
