#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

void get(char []);
void len(int);
int main()
{
 char s[50];
 int n;
 cout<<"\nHow many string do you want to enter :";
 cin>>n;
 for(int i=0;i<n;i++)
 {
  get(s);
 }
 len(n);
 return 0;
}
int i=0,a[50];
void get(char s[])
{
  cout<<"\nEnter String :" ;
  gets(s);
  a[i]=strlen(s);
  i++;
 }
void len(int n)
{
 for(i=0;i<n;i++)
 {
   cout<<"\nLength :";
   cout<<a[i];
 }
}
