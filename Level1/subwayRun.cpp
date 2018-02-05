/*
Arrnie is playing the new famous game Subway Runners.
In this game there are three lanes and one starts from any one of the three lanes.
Arrnie plays the game in the following manner :
Switch(1,2)
Switch(2,3)
Switch(1,2)
Switch(2,3).. and so on..

Switch(x,y) is defined as follows :
if Arrnie is on lane x, he switches to lane y.
if Arrnie is on lany y, he switches to lane x.
if he is neither on lane x nor on y, he stays on the current lane.

Given the current lane of Arrnie and the number of moves he has made,
 Print the number of the lane Arrnie started the game in.

Sample Input 0

4 3
Sample Output 0

2
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,x,ans;
    cin>>n>>x;
    while(n>0)
    {
        if(n%2==0)
        {
            if(x==2)
                x=3;
            else if(x==3)
                x=2;
        }
        else
        {
            if(x==1)
                x=2;
            else if(x==2)
                x=1;
        }
        n--;
    }
    cout<<x;
    return 0;
}
