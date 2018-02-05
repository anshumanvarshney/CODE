/*
Gru got some numbers with him to the dance club to watch his daughters perform. The numbers were N while 
he got them to the club, the numbers are gru's numbers so the disintegrate into two equal halves every second,
 if the number is odd, it breaks into two equal parts and leaves one "RIAX" everytime it breaks. 
 i.e. 5 will break into 2,2 and 1 riax They stop breaking once they're 0 and they vanish Say that the dance 
 is suffienctly long enough so that all numbers break off and vanish You look at the riaxs that lie with you now, 
 can you count them knowing the initial numbers?

NOTE : If a number breaks into two numbers, one of those numbers will disappear unless it is one.
 For example : 2 breaks into 1 and 1 giving two RIAX. 5 breaks into 2,2 giving 1 RIAX. However, 
 one 2 will disappear and only one 2 will remain.
 */
 
 #include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int count(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else if(n==3)
        return 3;
    else if(n==4)
        return 2;
    else if(n==5)
        return 3;
    else return 3;
}
/*
int riax(int n)
{
    int d,sum=0;
    while(n!=0)
    {
        d=n%2;
        sum+=count(d);
        n=n/2;
    }
}*/

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int n,a[10000],c,m,i;
 //   memset(c,0,sizeof(c));
    cin>>n;
    int sum=0;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        sum+=count(a[i]);
    }
        
    cout<<sum;
        
    
    return 0;
}
