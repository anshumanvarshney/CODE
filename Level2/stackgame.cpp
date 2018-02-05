/*
The very famous captain Oozora Tsubasa of football club Nankatsu FC decided to popularize football in Japan
 by organizing a football fest. The fest had many events for different sections of people.
For the awesome coders of CCC, there was an event called PASS and BACK.
In this event, the coders were given N passes and players having ids between 1 and 1000000.
Initially some player with a given id had the ball in his possession. The coders had to make a program 
to display the id of the player who possessed the ball after exactly N passes.


Description of the passes:
There were two kinds of passes:
1. P ID
2. B

Explanation :
For the first kind of pass, the player in possession of the ball passes the ball to player with id = ID while 
for the second kind of a pass,the player in possession of the ball passes the ball back to the player who 
had passed the ball to him.

Sample Input 0

1
10 23
P 86
P 63
P 60
B
P 47
B
P 99
P 9
B
B
Sample Output 0

Player 9
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    stack<long long int> s;
    long long int n,x,e,i,m2,y,m1;
    cin>>y;
    while(y--)
    {
        char p;
        cin>>n>>x;
        s.push(x);
        for(i=0;i<n;i++)
        {
            cin>>p;
            if(p=='P')
            {
                cin>>e;
                s.push(e);
            }
            else if(p=='B')
            {
                m1=s.top();
                s.pop();
                m2=s.top();
                s.pop();
                //cout<<m1<<" "<<m2<<"\n";
                s.push(m1);
                s.push(m2);
            }
        }
        cout<<"Player "<<s.top()<<"\n";
    }
    return 0;
}
