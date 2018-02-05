/*
Parliament in the capital city of Delhi has a rectangular shape with the size n×m meters.
 On the occasion of the city's anniversary,
 a decision was taken to pave the Square with square granite flagstones. Each flagstone is of the size a×a.

What is the least number of flagstones needed to pave the Square? It's allowed to cover the surface larger than
 the Parliament Square, but the Square has to be covered. It's not allowed to break the flagstones.
 The sides of flagstones should be parallel to the sides of the Square.
 
Output Format

Write the needed number of flagstones.

Sample Input 0

6 6 4(means 4*4 granite)
Sample Output 0

4
 */
 
 #include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long long int n,m,a,x=0,y=0;
    cin>>n>>m>>a;
    //int min=(n>m)?n:m;
    if(n%a==0)
    {
         x=n/a; 
    }
    if(m%a==0)
    {
        y=m/a;
    }
    if(x==0)
    {
        x=n/a;
        x++;
    }
    if(y==0)
    {
        y=m/a;
        y++;
    }
    cout<<x*y;
    return 0;
}