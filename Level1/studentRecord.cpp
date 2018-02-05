/*
Input:
2
2
Shrikanth 20 30 10 Ram 100 50 10
3
Adam 50 10 40 Suresh 22 1 56 Rocky 100 90 10

Output:
Ram 53
Rocky 66
*/
#include <iostream>
using namespace std;

int main() 
{
 int t,n,s1,s2,s3,avg;
 string s,r;
 cin>>t;
 while(t--)
 {
     cin>>n;
     cin>>s>>s1>>s2>>s3;
     r=s;
     avg=(s1+s2+s3)/3;
     n=n-1;
     while(n--)
     {
         cin>>s>>s1>>s2>>s3;
         if(((s1+s2+s3)/3)>avg)
         {
             avg=(s1+s2+s3)/3;
             r=s;
         }
     }
     cout<<r<<" "<<avg<<"\n";
     
 }
 return 0;
}