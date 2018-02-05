/*
Given a number of dates, sort them in such a way that the date that corresponds to the earliest
 day comes first and the date that corresponds to the latest day comes last.
 
 Sample Input 0

4
9 8 1996
31 4 1995
30 4 1996
25 12 1997
Sample Output 0

31 4 1995
30 4 1996
9 8 1996
25 12 1997
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct date
{
    int d;
    int m;
    int y;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    date o[100];
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>o[i].d>>o[i].m>>o[i].y;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(o[i].y>o[j].y)
                swap(o[i],o[j]);
            else if(o[i].y==o[j].y && o[i].m > o[j].m)
                swap(o[i],o[j]);
            else if(o[i].y==o[j].y && o[i].m == o[j].m && o[i].d > o[j].d)
                swap(o[i],o[j]);

        }
    }
    for(i=0;i<n;i++)
    {
        cout<<o[i].d<<" "<<o[i].m<<" "<<o[i].y;
        cout<<"\n";
    }
    
        return 0;
}
