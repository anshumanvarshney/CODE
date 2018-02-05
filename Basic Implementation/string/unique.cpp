#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main() {
  char s[10];
  int i,j,flag=0;
  cout<<"Enter String:";
  gets(s);
  for(i=0;s[i]!='\0';i++)
  {
    for(j=0;j<i;j++)
	{
		if(s[i]==s[j])
		{
			++flag;
	        break;
		}
	}
  }
  if(flag==0)
  {
	  cout<<"\nUnique\n\n";
  }
  else cout<<"\nNot a unique string\n\n";

  return 0;
}