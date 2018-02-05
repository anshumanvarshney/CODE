/*
A hotel manager has to process N advance bookings of rooms for the next season.
His hotel has K rooms.
Bookings contain an arrival date and a departure date.
He wants to find out whether there are enough rooms in the hotel to satisfy the demand.
Write a program that solves this problem in time O(N log N) .

Sample Input 0

3 1
1 2
3 6
5 8
Sample Output 0

no
Explanation 0

2 rooms are needed on days 5 and 6 while there are only 1 room.
*/

#include <bits/stdc++.h>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int n,i,j,k,a[1000000],d[1000000],c[1000000],l=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a[i]>>d[i];
    for(i=0;i<n;i++)
        c[l++]=a[i];
    for(i=0;i<n;i++)
        c[l++]=d[i];
    sort(c,c+l);
    //for(i=0;i<l;i++)
      //  cout<<c[i]<<" ";
    
    i=0;
    j=0;
    int count=0,m=-1,x=0;
    while(i<n&&j<n)
    {
        if(c[x]==a[i])
        {
            i++;
            x++;
            count++;
            m=max(m,count);
        }
        else if(c[x]==d[j])
        {
            j++;
            x++;
            count--;
        }
    }
    if(m<=k)
        cout<<"yes";
    else cout<<"no";
    
    return 0;
}
