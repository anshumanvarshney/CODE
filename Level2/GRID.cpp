/*
You are in an infinite 2-Dimensional Grid where each cell can be represented by its co-ordinates (x,y).

From each cell you can go to at most 8 different cells : 
- (x + 1, y)
- (x, y + 1)
- (x - 1, y)
- (x, y - 1)
- (x + 1, y + 1)
- (x + 1, y - 1)
- (x - 1, y + 1)
- (x - 1, y - 1)

Given a sequence of co-ordinates, calculate the minimum number of steps you will have to travel,
 starting at the first cell and ending at the last while visiting the cells in the given order.

Sample Input 0
0 0
1 1
1 2

Sample Output 0
2
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long long int a,b,res=0,x,y;
    cin>>x>>y;
    a=x;
    b=y;
    while(cin>>x>>y)
    {
        res+=max(abs(x-a),abs(y-b));
        a=x;
        b=y;
    }
    cout<<res;
    return 0;
}
