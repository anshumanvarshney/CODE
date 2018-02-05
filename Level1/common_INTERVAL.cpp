/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
Make sure the returned intervals are also sorted.

Sample Input 0

2 2 5
1 3
6 9
Sample Output 0

1 5
6 9
Sample Input 1

5 4 9
1 2
3 5
6 7
8 10
12 16
Sample Output 1

1 2
3 10
12 16
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,x,t,y,i,j,a[1000],b[1000],c[1000];
    cin>>n>>x>>y;
    for(i=0;i<n;i++)
        cin>>a[i]>>b[i];
    memset(c,0,sizeof(c));
    for(i=x;i<y;i++)
        c[i]=1;
    int m=y;
    m=max(m,b[n-1]);
    for(i=0;i<n;i++)  
    {
        x=a[i];
        y=b[i];
        for(j=x;j<y;j++)
            c[j]=1;
    }
    c[m]=0;
    for(i=0;i<m;i++)
    {
        if(c[i]==1&&c[i-1]==0)
            cout<<i<<" ";
        if(c[i]==0 && c[i-1]==1)
            cout<<i<<"\n";
    }
    cout<<i<<"\n";
   
   
    return 0;
}
