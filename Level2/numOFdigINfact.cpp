/*
As simple as the title, given a number N, print the number of digits in N!
N! is defined as : N! = 1*2*3...(N-1)*N
0! = 0 and 1! = 1.
No number ever contains any leading zeros.

Sample Input 0
6
Sample Output 0
3
Explanation 0
6! = 1x2x3x4x5x6 = 720 which has 3 digits. So the answer is 3.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int count(int n)
{
    if(n<0)
        return 0;
    else if(n<=1)
        return 1;
    double d=0;
    for(int i=2;i<=n;i++)
        d+=log10(i);
    return floor(d)+1;
    
}
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    cout<<count(n);
    return 0;
}
