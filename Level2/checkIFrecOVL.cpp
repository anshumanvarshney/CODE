
/*
Given two rectangles, find if the given two rectangles overlap or not.

Note that a rectangle can be represented by two coordinates, top left and bottom right. So mainly we are 
given following four coordinates.
l1: Top Left coordinate of first rectangle.
r1: Bottom Right coordinate of first rectangle.
l2: Top Left coordinate of second rectangle.
r2: Bottom Right coordinate of second rectangle.

Two rectangles do not overlap if one of the following conditions is true.
1) One rectangle is above top edge of other rectangle.
2) One rectangle is on left side of left edge of other rectangle.
*/


#include<bits/stdc++.h>
using namespace std;

struct rec
{
    int x;
    int y;
};

int main()
{
    int p;
    cin>>p;
    while(p--)
    {
    int flag=1;
    rec l1,l2,r1,r2;
    cin>>l1.x>>l1.y;
    cin>>r1.x>>r1.y;
    cin>>l2.x>>l2.y;
    cin>>r2.x>>r2.y;
    if (l1.x > r2.x || l2.x > r1.x)
        flag=0;
 
    if (l1.y < r2.y || l2.y < r1.y)
        flag=0;
    if(flag==1)
        cout<<1;
    else cout<<0;
    cout<<"\n";
    }
	return 0;
}