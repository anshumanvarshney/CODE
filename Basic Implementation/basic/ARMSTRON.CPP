#include<iostream>
using namespace std;

int main()
{
 
 int n,d,a,s=0;
 cout<<"Enter a no :";
 cin>>n;
 a=n;
 while(a!=0)//int(0.11) = 0
 {
  d=a%10;
  s+=d*d*d;
  a=a/10;
 }
 if(s==n)
  cout<<"\nArmstrong" ;
 else
  cout<<"\nNot a armstrong number";
 
 return 0;
}