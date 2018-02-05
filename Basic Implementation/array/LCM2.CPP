#include<iostream.h>
#include<conio.h>

int main()
{
 clrscr();
 int a,b,max;
 cout<<"Enter two no :";
 cin>>a>>b;
 max=(a>b)?a:b;
 while(max<=(a*b))
 if(max%a==0&&max%b==0)
 {

  cout<<"\nLCM :"<<max;
  break;
 }
 else max++;
 getch();
 return 0;
}