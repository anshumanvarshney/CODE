/*
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN.
In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. 
By flipping, we mean change character 0 to 1 and vice-versa.
Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised.
If you don’t want to perform the operation, print -1.
Else, print two elements denoting L and R.
If there are multiple solutions, return the lexicographically smallest pair of L and R.

Sample Input 0

010
Sample Output 0

1 1
Explanation 0

S = 010

Pair of [L, R] | Final string
______|____
[1 1] | 110
[1 2] | 100
[1 3] | 101
[2 2] | 000
[2 3] | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].

Sample Input 1

111
Sample Output 1

-1
Explanation 1

No operation can give us more than three 1s in final string.

i/p:
1 0 0 1 1 0 1 0 1 1 1
o/p=[1 2]
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;
    int sum=0,temp=0,i,l=0,r=0,a[10];
    a[0]=a[1]=-1;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='0')
            temp++;
        else if(s[i]=='1')
            temp--;
        
        if(temp<0)
        {
            temp=0;
            l=i+1;
        }
        if(sum<temp)
        {
            sum=temp;
            a[0]=l;
            a[1]=i;
        }
    }
    if(a[0]!=-1&&a[1]!=-1)
        cout<<a[0]+1<<" "<<a[1]+1;
    else cout<<-1;   
    return 0;
}
