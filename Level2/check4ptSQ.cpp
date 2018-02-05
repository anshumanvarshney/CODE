/*
Check if given four points form a square
Given coordinates of four points in a plane, find if the four points form a square or not.

Input:
2
20 20 20 10 10 20 10 10
10 10 10 10 20 10 20 30

Output:
1
0
*/
#include<bits/stdc++.h>
using namespace std;

struct sq
{
    int x;
    int y;
};

int main()
{
    sq a,b,c,d;
    int p;
    cin>>p;
    while(p--)
    {
    cin>>a.x>>a.y;
    cin>>b.x>>b.y;
    cin>>c.x>>c.y;
    cin>>d.x>>d.y;
    int p,q,r,s;
    p=abs(a.x-d.x);
    q=abs(a.y-b.y);
    r=abs(b.x-c.x);
    s=abs(c.y-d.y);
    if(p==q && q==r && r==s)
    {
        cout<<1;
    }
    else cout<<0;
    cout<<"\n";
    }
	return 0;
}