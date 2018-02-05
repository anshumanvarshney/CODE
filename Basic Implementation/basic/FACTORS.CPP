#include<iostream.h>
#include<conio.h>

int main()
{
 clrscr();
 int i,a,c=0;
 cout<<"\nEnter a number :";
 cin>>a;
 for(i=2;i<=a;i++)
 {
   if(a%i==0)
    {
     cout<<i<<" ";
     c++;
    }
 }
 cout<<"\nThe no. of factors :"<<c;
 getch();
 return 0;
}